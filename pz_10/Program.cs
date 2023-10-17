using System;
using System.Runtime.InteropServices;

namespace pz_10
{
    class Program
    {
        const int PAGE_SIZE = 4096; // 1 страница памяти = 4096 байт

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern IntPtr VirtualAlloc(IntPtr lpAddress, uint dwSize, uint flAllocationType, uint flProtect);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool VirtualFree(IntPtr lpAddress, uint dwSize, uint dwFreeType);

        [DllImport("kernel32.dll")]
        static extern int VirtualQuery(IntPtr lpAddress, out MEMORY_BASIC_INFORMATION lpBuffer, uint dwLength);

        [StructLayout(LayoutKind.Sequential)]
        struct MEMORY_BASIC_INFORMATION
        {
            public IntPtr BaseAddress;
            public IntPtr AllocationBase;
            public uint AllocationProtect;
            public IntPtr RegionSize;
            public uint State;
            public uint Protect;
            public uint Type;
        }

        static void Main()
        {
            IntPtr memoryAddress = VirtualAlloc(IntPtr.Zero, PAGE_SIZE, 0x00001000, 0x00000004); // Резервирование и отображение памяти

            if (memoryAddress == IntPtr.Zero)
            {
                Console.WriteLine("Не удалось зарезервировать память.");
                return;
            }

            FillMemoryWith7Fh(memoryAddress, PAGE_SIZE, 0x7F); // Заполнение памяти значением 7Fh

            MEMORY_BASIC_INFORMATION memoryInfo;
            if (VirtualQuery(memoryAddress, out memoryInfo, (uint)Marshal.SizeOf(typeof(MEMORY_BASIC_INFORMATION))) != 0)
            {
                Console.WriteLine($"Размер: {memoryInfo.RegionSize.ToInt32()} байт");
                Console.WriteLine($"Защита: 0x{memoryInfo.AllocationProtect.ToString("X")}");
                Console.WriteLine($"Базовый адрес: 0x{memoryInfo.BaseAddress.ToString("X")}");
                Console.WriteLine($"Состояние: 0x{memoryInfo.State.ToString("X")}");
            }

            VirtualFree(memoryAddress, 0, 0x8000); // Освобождение памяти
        }

        static void FillMemoryWith7Fh(IntPtr address, int size, byte value)
        {
            byte[] buffer = new byte[size];
            for (int i = 0; i < buffer.Length; i++)
            {
                buffer[i] = value;
            }

            Marshal.Copy(buffer, 0, address, size);
        }
    }
}

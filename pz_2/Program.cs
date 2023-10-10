using System;
using System.Runtime.InteropServices;

namespace pz_2
{
    class Program
    {
        [DllImport("kernel32.dll")]
        public static extern void GetSystemInfo(out SYSTEM_INFO lpSystemInfo);

        // Импортирование функции из WIN32 API
        [DllImport("kernel32.dll")]
        public static extern void GetVersionEx(ref OSVERSIONINFO osVersionInfo);

        [StructLayout(LayoutKind.Sequential)]
        public struct SYSTEM_INFO
        {
            public ushort processorArchitecture;
            public ushort reserved;
            public uint pageSize;
            public IntPtr minimumApplicationAddress;
            public IntPtr maximumApplicationAddress;
            public IntPtr activeProcessorMask;
            public uint numberOfProcessors;
            public uint processorType;
            public uint allocationGranularity;
            public ushort processorLevel;
            public ushort processorRevision;
        }
        // Структура для хранения информации об операционной системе
        [StructLayout(LayoutKind.Sequential)]
        public struct OSVERSIONINFO
        {
            public int dwOSVersionInfoSize;
            public int dwMajorVersion;
            public int dwMinorVersion;
            public int dwBuildNumber;
            public int dwPlatformId;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 128)]
            public string szCSDVersion;
            public UInt16 wServicePackMajor;
            public UInt16 wServicePackMinor;
            public UInt16 wSuiteMask;
            public byte wProductType;
            public byte wReserved;
        }
        static void Main(string[] args)
        {
            string GetComputerName = Environment.MachineName;
            Console.WriteLine("Имя компьютера: " + GetComputerName);

            string GetSystemDirectory = Environment.SystemDirectory;
            string GetWindowsDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Windows);
            Console.WriteLine("Пути к системным каталогам Windows: " + GetWindowsDirectory + "; " + GetSystemDirectory);

            
            string osVersion = GetOSVersion();
            Console.WriteLine($"Версия операционной системы: {osVersion}");

            Console.ReadLine();
        }

        

        
        static string GetOSVersion()
        {
            OSVERSIONINFO osVersionInfo = new OSVERSIONINFO();
            osVersionInfo.dwOSVersionInfoSize = Marshal.SizeOf(typeof(OSVERSIONINFO));
            GetVersionEx(ref osVersionInfo);
            return $"{osVersionInfo.dwMajorVersion}.{osVersionInfo.dwMinorVersion}.{osVersionInfo.dwBuildNumber} {osVersionInfo.szCSDVersion}";
        }
    }
}

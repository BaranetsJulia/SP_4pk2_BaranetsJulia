using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace pz_8
{
    class Program
    {
        // Импорт функции HeapCreate
        [DllImport("kernel32.dll", SetLastError = true)]
        static extern IntPtr HeapCreate(uint flOptions, UIntPtr dwInitialSize, UIntPtr dwMaximumSize);

        static void Main()
        {
            // Вызов HeapCreate для создания heap
            IntPtr heap = HeapCreate(0, UIntPtr.Zero, UIntPtr.Zero);

            // Проверка на успешность вызова HeapCreate
            if (heap != IntPtr.Zero)
            {
                Console.WriteLine("Heap создана успешно!");

                // Запускаем потоки
                Thread thread1 = new Thread(LongRunningAction);
                Thread thread2 = new Thread(LongRunningAction);
                thread1.Start();
                thread2.Start();

                Console.ReadKey();
            }
            else
            {
                Console.WriteLine("Ошибка в создании!");
            }
        }

        static void LongRunningAction()
        {
            // бесконечный цикл
            while (true)
            {
                // ...
            }
        }
    }
}

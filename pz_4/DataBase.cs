using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace pz_4
{
    public class DataBase //класс имитирует работу с БД
    {
        public void SaveData(string text) //метод, для вывода сообщения о сохранении данных
        {
            lock (this) //блокировка потока
            {
                for (int i = 0; i < 5; i++)
                {
                    Console.WriteLine("SaveData: " + text);
                    Thread.Sleep(1000);
                }
            }
        }
    }
}

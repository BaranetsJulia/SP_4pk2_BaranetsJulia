using System;
using System.Threading;

namespace pz_4
{
    class Program
    {
        public static DataBase db = new DataBase();

        static void Main(string[] args)
        {
            Thread worker1 = new Thread(new ThreadStart(WorkerThreadMethod1));
            Thread worker2 = new Thread(WorkerThreadMethod2);

            worker1.Start();
            worker2.Start();

            Console.ReadLine();
        }

        static void WorkerThreadMethod1()
        {
            Console.WriteLine("Worker thread 1 started");
            db.SaveData("Data from Worker thread 1");
            Console.WriteLine("Worker thread 1 ended");
        }

        static void WorkerThreadMethod2()
        {
            Console.WriteLine("Worker thread 2 started");
            db.SaveData("Data from Worker thread 2");
            Console.WriteLine("Worker thread 2 ended");
        }
    }
}

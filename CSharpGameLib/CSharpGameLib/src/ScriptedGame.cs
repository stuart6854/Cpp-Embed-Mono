using System;
using System.Threading;

namespace CSharpGameLib
{
    public class ScriptedGame : IGame
    {
        private int someArg;

        public ScriptedGame(int someArg)
        {
            this.someArg = someArg;
        }

        public void keyEvent(char key)
        {
            Console.Out.Write("keyEvent: ");
            Console.Out.Write(key);
            Console.Out.WriteLine();

            if (key == 'f')
            {
                Console.Out.WriteLine("F was pressed.");
            }
        }

        public bool tick()
        {
            Engine.Console.clearBuffer();

            Engine.Console.putString("Hello World: " + someArg);

            Engine.Console.flush();

            // Sleep and Return 
            Thread.Sleep(4000);
            return false;
        }
    }
}
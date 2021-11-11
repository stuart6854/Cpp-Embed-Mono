namespace CSharpGameLib
{
    /*
     * Main class
     */
    public class GameMain
    {
        /*
         * Main function
         */
        public static IGame main()
        {
            int val = Engine.RandomNum.getRandomInt();
            System.Console.Out.WriteLine(val);
            return new ScriptedGame(val);
        }
    }
}
using System.Runtime.CompilerServices;

namespace Engine
{
    public class RandomNum
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int getRandomInt();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern int getRandomFloat();
    }
}
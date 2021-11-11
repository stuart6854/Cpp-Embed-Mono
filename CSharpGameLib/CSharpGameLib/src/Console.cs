using System.Runtime.CompilerServices;

namespace Engine
{
    public class Console
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void clearBuffer();
        

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void putString(string str);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void flush();
    }
}
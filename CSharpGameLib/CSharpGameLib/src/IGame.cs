namespace CSharpGameLib
{
    public interface IGame
    {
        void keyEvent(char key);
        bool tick();
    }
}
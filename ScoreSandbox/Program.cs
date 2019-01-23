using ScoreWrapper;
namespace ScoreSandbox
{
	class Program
	{
		static void Main(string[] args)
		{
			Entity e = new Entity("The Wallman 楊宏章", 20, 35);
			e.Move(5, -10);
			System.Console.WriteLine(e.XPosition + " " + e.YPosition);
			e.DisplayImage("D:\\mia中文\\Mia201712101259.jpg");
			System.Console.WriteLine(e.GetData());
			System.Console.Read();
		}
	}
}

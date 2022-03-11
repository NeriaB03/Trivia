using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        public static Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        public static IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 666);
        public static bool isClosing = false;
        public static bool isUserExistOrIsPasswordMatch = false;
        public static bool isRoomAdmin = false;
        public static bool gameStarted = false;
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Splash_Screen());
            while (!isUserExistOrIsPasswordMatch && !isClosing)
            {
                Application.Run(new Login());
                if (!isUserExistOrIsPasswordMatch && !isClosing) Application.Run(new Signup());
            }
            while (!isClosing)
            {
                //proceed to menu screen
                Application.Run(new MainMenu());
                if (!isClosing)
                {
                    Application.Run(new Room());
                    if (gameStarted)
                    {
                        //start game
                        Console.WriteLine("Game Started Screen...");
                        isClosing = true;
                    }
                }
            }
            Application.Exit();
        }
        public static void logOut()
        {
            Client.Program.isClosing = true;
            //log out
            string loginReq = "8" + "0000";
            Console.WriteLine(loginReq);
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(loginReq));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            Client.Program.sock.Close();
        }
    }
    class User
    {
        public string username
        {
            get; set;
        }
        public string password
        {
            get; set;
        }
    }
    class SignupUser
    {
        public string username
        {
            get; set;
        }
        public string password
        {
            get; set;
        }
        public string email
        {
            get;set;
        }
    }
    class Status
    {
        public int status
        {
            get;set;
        }
    }
    class Error
    {
        public string Message
        {
            get;set;
        }
    }
    class RoomInfo
    {
        public string roomName
        {
            get;set;
        }
        public int maxUsers
        {
            get;set;
        }
        public int questionCount
        {
            get;set;
        }
        public int questionTimeout
        {
            get;set;
        }
    }
    class RoomName
    {
        public string roomName
        {
            get;set;
        }
    }
    class RoomState
    {
        public int status { get;set; }
        public string admin { get;set; }
        public int answerTimeout { get;set; }
        public int hasGameBegun { get;set; }
        public int isActive { get;set; }
        public int maxPlayers { get;set; }
        public string name { get;set; }
        public string players { get;set; }
        public int questionCount { get;set; }
    }
}

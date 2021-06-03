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
            if (isClosing) Application.Exit();
            else
            {
                //proceed to game screen
                Application.Run(new MainMenu());
                if (isClosing) Application.Exit();
            }
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
    class Room
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
}

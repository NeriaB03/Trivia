using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    public partial class Splash_Screen : Form
    {
        private Stopwatch sw;
        private static Thread trd;
        public Splash_Screen()
        {
            InitializeComponent();
            sw = Stopwatch.StartNew();
            trd = new Thread(connectToServer);
            trd.Start();
        }
        private void connectToServer()
        {
            Thread.Sleep(1000);
            while(!Client.Program.sock.Connected)
            {
                try
                {
                    Client.Program.sock.Connect(Client.Program.localEndPoint);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error while connecting to the server...");
                    Thread.Sleep(1000);
                }
            }
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            panelSlide.Left += 2;
            if (panelSlide.Left > 200)
            {
                panelSlide.Left = -20;
            }
            if(Client.Program.sock.Connected)
            {
                runLoginForm();
            }
        }
        private void runLoginForm()
        {
            trd.Abort();
            timer1.Stop();
            timer1.Enabled = false;
            sw.Stop();
            Thread.Sleep(500);
            this.Close();

        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            Client.Program.sock.Close();
            Client.Program.isUserExistOrIsPasswordMatch = false;
            Client.Program.isClosing = true;
            this.Close();
        }
    }
}

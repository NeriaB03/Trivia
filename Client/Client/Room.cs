
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft;
using System.Threading;

namespace Client
{
    public partial class Room : Form
    {
        private static Thread roomStateTrd;
        public Room()
        {
            InitializeComponent();
            setRoomInfoLabels();
            roomStateTrd = new Thread(updateRoomData);
            roomStateTrd.Start();
            if (Program.isRoomAdmin) startButton.Visible = true;
        }
        private void setRoomInfoLabels()
        {
            string request = '#' + "0000";
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            string json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
            RoomState roomState = JsonConvert.DeserializeObject<RoomState>(json);
            string[] players = roomState.players.Split(',');
            players = players.Take(players.Count() - 1).ToArray(); //remove last element (because its empty)
            welcomeLabel.Text = welcomeLabel.Text.ToString() + roomState.admin + "'s room";
            timePerQuestionLabel.Text = timePerQuestionLabel.Text.ToString() + roomState.answerTimeout.ToString();
            maxNumOfPlayersLabel.Text = maxNumOfPlayersLabel.Text.ToString() + roomState.maxPlayers.ToString();
            numOfQuestionsLabel.Text = numOfQuestionsLabel.Text.ToString() + roomState.questionCount.ToString();
            roomNameLabel.Text = roomNameLabel.Text.ToString() + roomState.name.ToString();
            currentNumOfPlayersLabel.Text = players.Length.ToString();
            playersList.Text = roomState.players;
        }
        private void updateRoomData()
        {
            while (true)
            {
                Thread.Sleep(3000);
                string request = '#' + "0000";
                Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
                byte[] bytes = new byte[1024];
                int bytesRec = Client.Program.sock.Receive(bytes);
                string json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
                RoomState roomState = JsonConvert.DeserializeObject<RoomState>(json);
                string[] players = { };
                if (roomState != null)
                {
                    players = roomState.players.Split(',');
                    players = players.Take(players.Count() - 1).ToArray(); //remove last element (because its empty)
                }
                if (roomState.isActive == 0 && !Program.isRoomAdmin)
                {
                    leaveRoom();
                }
                if(roomState.hasGameBegun == 1 && !Program.isRoomAdmin)
                {
                    startGame();
                    break;
                }
                if (currentNumOfPlayersLabel.Text.ToString() != players.Length.ToString())
                {
                    BackgroundWorker backgroundWorker = new BackgroundWorker();
                    backgroundWorker.DoWork += new DoWorkEventHandler(changePlayersLabelWithBGWorker);
                    backgroundWorker.RunWorkerAsync(argument: roomState);
                }
            }
        }
        private void changePlayersLabelWithBGWorker(object sender, DoWorkEventArgs e)
        {
            RoomState roomState = (RoomState)e.Argument;
            string[] players = { };
            if (roomState != null)
            {
                players = roomState.players.Split(',');
                players = players.Take(players.Count() - 1).ToArray(); //remove last element (because its empty)
            }
            currentNumOfPlayersLabel.Invoke((MethodInvoker)delegate
            {
                currentNumOfPlayersLabel.Text = players.Length.ToString();
            });
            playersList.Invoke((MethodInvoker)delegate
            {
                playersList.Text = roomState.players;
            });
        }
        private void leaveRoom()
        {
            char msgCode;
            if (Program.isRoomAdmin) msgCode = '!';
            else msgCode = '$';
            string request = msgCode + "0000";
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            string json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
            roomStateTrd.Abort();
        }
        private void startGame()
        {
            string request = '@' + "0000";
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            string json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
            if (JsonConvert.DeserializeObject<Status>(json).status == 1)
            {
                MessageBox.Show("GAME STARTED SUCCESSFULLY","GameStatus");
                Program.gameStarted = true;
                roomStateTrd.Abort();
            }
            else
            {
                MessageBox.Show("GAME ERROR", "GameStatus");
            }
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            leaveRoom();
            Program.isClosing = true;
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            startGame();
        }

        private void leaveButton_Click(object sender, EventArgs e)
        {
            leaveRoom();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (!roomStateTrd.IsAlive) this.Close();
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft;
using Newtonsoft.Json;

namespace Client
{
    public partial class MainMenu : Form
    {
        private int whichScreen;
        private Stopwatch sw;
        public MainMenu()
        {
            InitializeComponent();
            sw = Stopwatch.StartNew();
            whichScreen = 1;
        }
        private void checkSendButtonButtonValidate()
        {
            if (sendRoomButton.Text.Equals("JOIN"))
            {
                if (String.IsNullOrEmpty(roomnameTB.Text))
                {
                    sendRoomButton.Enabled = false;
                    sendRoomButton.Cursor = Cursors.No;
                    sendRoomButton.BackColor = Color.FromArgb(175, 220, 249);
                }
                else
                {
                    sendRoomButton.Enabled = true;
                    sendRoomButton.Cursor = Cursors.Hand;
                    sendRoomButton.BackColor = Color.FromArgb(41, 128, 185);

                }
            }
            else
            {
                if (String.IsNullOrEmpty(roomnameTB.Text) || String.IsNullOrEmpty(numOfPlayersTB.Text) || String.IsNullOrEmpty(numOfQuestionsTB.Text) || String.IsNullOrEmpty(timePerQuestionTB.Text))
                {
                    sendRoomButton.Enabled = false;
                    sendRoomButton.Cursor = Cursors.No;
                    sendRoomButton.BackColor = Color.FromArgb(175, 220, 249);
                }
                else
                {
                    sendRoomButton.Enabled = true;
                    sendRoomButton.Cursor = Cursors.Hand;
                    sendRoomButton.BackColor = Color.FromArgb(41, 128, 185);

                }
            }
        }

        private bool checkValidateOfMaxUsersTB()
        {
            try
            {
                int number = int.Parse(numOfPlayersTB.Text.ToString());
                return true;
            }
            catch(Exception e)
            {
                return false;
            }
        }
        private bool checkValidateOfMaxQuestionsTB()
        {
            try
            {
                int number = int.Parse(numOfQuestionsTB.Text.ToString());
                return true;
            }
            catch (Exception e)
            {
                return false;
            }
        }

        private bool checkValidateOfTimePerQuestionTB()
        {
            try
            {
                int number = int.Parse(timePerQuestionTB.Text.ToString());
                return true;
            }
            catch (Exception e)
            {
                return false;
            }
        }

        private void joinRoomButton_Click(object sender, EventArgs e)
        {
            joinRoomButton.BackColor = System.Drawing.Color.WhiteSmoke;
            joinRoomButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.WhiteSmoke;
            joinRoomButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.WhiteSmoke;
            if (whichScreen == 2)
            {
                createRoomButton.BackColor = panel1.BackColor;
                createRoomButton.FlatAppearance.MouseDownBackColor = panel1.BackColor;
                createRoomButton.FlatAppearance.MouseOverBackColor = panel1.BackColor;
                numberOfPlayersPanel.Visible = false;
                numberOfQuestionsPanel.Visible = false;
                timePerQuestionPanel.Visible = false;
                sendRoomButton.Text = "JOIN";
                roomnameTB.Text = "";
                numOfPlayersTB.Text = "";
                numOfQuestionsTB.Text = "";
                timePerQuestionTB.Text = "";
                errorLabel.Visible = false;
            }
            else if (whichScreen == 3)
            {
                statsButton.BackColor = panel1.BackColor;
                statsButton.FlatAppearance.MouseDownBackColor = panel1.BackColor;
                statsButton.FlatAppearance.MouseOverBackColor = panel1.BackColor;
                roomNamePanel.Visible = true;
                sendRoomButton.Enabled = true;
                sendRoomButton.Visible = true;
                totalAnswersPanel.Visible = false;
                correctAnswersPanel.Visible = false;
                totalAnswersLabel.Visible = false;
                totalGamesLabel.Visible = false;
                averageTimeLabel.Visible = false;
                firstPlaceHighScore.Visible = false;
                secondPlaceHighScore.Visible = false;
                thirdPlaceHighScore.Visible = false;
                //reset all labels
                totalGamesLabel.Text = "Total games: ";
                averageTimeLabel.Text = "Average time: ";
                firstPlaceHighScore.Text = "First highest score: ";
                secondPlaceHighScore.Text = "Second highest score: ";
                thirdPlaceHighScore.Text = "Third highest score: ";
            }
            whichScreen = 1;
        }

        private void createRoomButton_Click(object sender, EventArgs e)
        {
            numberOfPlayersPanel.Visible = true;
            numberOfQuestionsPanel.Visible = true;
            timePerQuestionPanel.Visible = true;
            createRoomButton.BackColor = System.Drawing.Color.WhiteSmoke;
            createRoomButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.WhiteSmoke;
            createRoomButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.WhiteSmoke;
            if (whichScreen == 1)
            {
                joinRoomButton.BackColor = panel1.BackColor;
                joinRoomButton.FlatAppearance.MouseDownBackColor = panel1.BackColor;
                joinRoomButton.FlatAppearance.MouseOverBackColor = panel1.BackColor;
                sendRoomButton.Text = "CREATE";
                roomnameTB.Text = "";
                errorLabel.Visible = false;
            }
            else if (whichScreen == 3)
            {
                statsButton.BackColor = panel1.BackColor;
                statsButton.FlatAppearance.MouseDownBackColor = panel1.BackColor;
                statsButton.FlatAppearance.MouseOverBackColor = panel1.BackColor;
                roomNamePanel.Visible = true;
                sendRoomButton.Enabled = true;
                sendRoomButton.Visible = true;
                totalAnswersPanel.Visible = false;
                correctAnswersPanel.Visible = false;
                totalAnswersLabel.Visible = false;
                totalGamesLabel.Visible = false;
                averageTimeLabel.Visible = false;
                firstPlaceHighScore.Visible = false;
                secondPlaceHighScore.Visible = false;
                thirdPlaceHighScore.Visible = false;
                //reset all labels
                totalGamesLabel.Text = "Total games: ";
                averageTimeLabel.Text = "Average time: ";
                firstPlaceHighScore.Text = "First highest score: ";
                secondPlaceHighScore.Text = "Second highest score: ";
                thirdPlaceHighScore.Text = "Third highest score: ";
            }
            whichScreen = 2;
        }

        private void statsButton_Click(object sender, EventArgs e)
        {
            roomNamePanel.Visible = false;
            sendRoomButton.Enabled = false;
            sendRoomButton.Visible = false;
            statsButton.BackColor = System.Drawing.Color.WhiteSmoke;
            statsButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.WhiteSmoke;
            statsButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.WhiteSmoke;
            if (whichScreen == 1)
            {
                joinRoomButton.BackColor = panel1.BackColor;
                joinRoomButton.FlatAppearance.MouseDownBackColor = panel1.BackColor;
                joinRoomButton.FlatAppearance.MouseOverBackColor = panel1.BackColor;
                roomnameTB.Text = "";
                errorLabel.Visible = false;
            }
            else if (whichScreen == 2)
            {
                createRoomButton.BackColor = panel1.BackColor;
                createRoomButton.FlatAppearance.MouseDownBackColor = panel1.BackColor;
                createRoomButton.FlatAppearance.MouseOverBackColor = panel1.BackColor;
                numberOfPlayersPanel.Visible = false;
                numberOfQuestionsPanel.Visible = false;
                timePerQuestionPanel.Visible = false;
                roomnameTB.Text = "";
                numOfPlayersTB.Text = "";
                numOfQuestionsTB.Text = "";
                timePerQuestionTB.Text = "";
            }
            whichScreen = 3;

            //get personal stats
            string request = '6' + "0000";
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            string json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
            if (json != "NULL")
            {
                string[] allStats = json.Split(',');
                allStats = allStats.Take(allStats.Count() - 1).ToArray(); //remove last element (because its empty)
                correctAnswersPanel.Size = new Size((int.Parse(allStats[2]) * 200) / int.Parse(allStats[1]), correctAnswersPanel.Height);//allStats[2] = correct answers,allStats[1] = total answers
                totalAnswersPanel.Visible = true;
                correctAnswersPanel.Visible = true;
                totalAnswersLabel.Visible = true;
                totalGamesLabel.Visible = true;
                averageTimeLabel.Visible = true;
                totalGamesLabel.Text = totalGamesLabel.Text.ToString() + allStats[3];//allStats[3] = total games
                averageTimeLabel.Text = averageTimeLabel.Text.ToString() + allStats[4];//allStats[4] = average time
            }
            else
            {
                correctAnswersPanel.Size = new Size(0,correctAnswersPanel.Height);
                totalAnswersPanel.Visible = true;
                correctAnswersPanel.Visible = true;
                totalAnswersLabel.Visible = true;
                totalGamesLabel.Visible = true;
                averageTimeLabel.Visible = true;
                totalGamesLabel.Text = totalGamesLabel.Text.ToString() + "0";
                averageTimeLabel.Text = averageTimeLabel.Text.ToString() + "NULL";
            }

            //get public highest scores
            request = '0' + "0000";
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
            bytesRec = Client.Program.sock.Receive(bytes);
            json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
            
            string[] highestScores = json.Split(',');
            highestScores = highestScores.Take(highestScores.Count() - 1).ToArray(); //remove last element (because its empty)
            firstPlaceHighScore.Visible = true;
            secondPlaceHighScore.Visible = true;
            thirdPlaceHighScore.Visible = true;
            switch (highestScores.Length)
            {
                case 0:
                    firstPlaceHighScore.Text = firstPlaceHighScore.Text.ToString() + "NULL";
                    secondPlaceHighScore.Text = secondPlaceHighScore.Text.ToString() + "NULL";
                    thirdPlaceHighScore.Text = thirdPlaceHighScore.Text.ToString() + "NULL";
                    break;
                case 1:
                    firstPlaceHighScore.Text = firstPlaceHighScore.Text.ToString() + highestScores[0];
                    secondPlaceHighScore.Text = secondPlaceHighScore.Text.ToString() + "NULL";
                    thirdPlaceHighScore.Text = thirdPlaceHighScore.Text.ToString() + "NULL";
                    break;
                case 2:
                    firstPlaceHighScore.Text = firstPlaceHighScore.Text.ToString() + highestScores[0];
                    secondPlaceHighScore.Text = secondPlaceHighScore.Text.ToString() + highestScores[1];
                    thirdPlaceHighScore.Text = thirdPlaceHighScore.Text.ToString() + "NULL";
                    break;
                case 3:
                    firstPlaceHighScore.Text = firstPlaceHighScore.Text.ToString() + highestScores[0];
                    secondPlaceHighScore.Text = secondPlaceHighScore.Text.ToString() + highestScores[1];
                    thirdPlaceHighScore.Text = thirdPlaceHighScore.Text.ToString() + highestScores[2];
                    break;
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Program.logOut();
            this.Close();
        }

        private void roomnameTB_TextChanged(object sender, EventArgs e)
        {
            checkSendButtonButtonValidate();
        }

        private void numOfPlayersTB_TextChanged(object sender, EventArgs e)
        {
            checkSendButtonButtonValidate();
        }

        private void numOfQuestionsTB_TextChanged(object sender, EventArgs e)
        {
            checkSendButtonButtonValidate();
        }

        private void timePerQuestionTB_TextChanged(object sender, EventArgs e)
        {
            checkSendButtonButtonValidate();
        }

        private void sendRoomButton_Click(object sender, EventArgs e)
        {
            if (sendRoomButton.Text.Equals("JOIN"))
            {
                object room = new RoomName
                {
                    roomName = roomnameTB.Text.ToString(),
                };
                string json = JsonConvert.SerializeObject(room, Formatting.Indented);
                string request = '4' + json.Length.ToString("D4") + json;
                Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
                byte[] bytes = new byte[1024];
                int bytesRec = Client.Program.sock.Receive(bytes);
                json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
                if (JsonConvert.DeserializeObject<Status>(json).status == 1)
                {
                    errorLabel.Visible = false;
                    Program.isRoomAdmin = false;
                    Program.isClosing = false;
                    this.Close();
                }
                else
                {
                    errorLabel.Text = "Room does not exists...";
                    errorLabel.Visible = true;
                }
            }
            else
            {
                if (checkValidateOfMaxUsersTB() && checkValidateOfMaxQuestionsTB() && checkValidateOfTimePerQuestionTB())
                {
                    maxUsersError.Clear();
                    maxQustionsError.Clear();
                    timePerQuestionError.Clear();
                    object roomInfo = new RoomInfo
                    {
                        roomName = roomnameTB.Text.ToString(),
                        maxUsers = int.Parse(numOfPlayersTB.Text.ToString()),
                        questionCount = int.Parse(numOfQuestionsTB.Text.ToString()),
                        questionTimeout = int.Parse(timePerQuestionTB.Text.ToString())
                    };
                    string json = JsonConvert.SerializeObject(roomInfo, Formatting.Indented);
                    string request = '9' + json.Length.ToString("D4") + json;
                    Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(request));
                    byte[] bytes = new byte[1024];
                    int bytesRec = Client.Program.sock.Receive(bytes);
                    json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
                    if (JsonConvert.DeserializeObject<Status>(json).status == 1)
                    {
                        errorLabel.Visible = false;
                        Program.isRoomAdmin = true;
                        this.Close();
                    }
                    else
                    {
                        errorLabel.Text = "Room already exists...";
                        errorLabel.Visible = true;
                    }
                }
                else
                {
                    errorLabel.Text = "Number can contain numbers only...";
                    errorLabel.Visible = true;
                    if (!checkValidateOfMaxUsersTB()) maxUsersError.SetError(numOfPlayersTB, "error");
                    else maxUsersError.Clear();
                    if (!checkValidateOfMaxQuestionsTB()) maxQustionsError.SetError(numOfQuestionsTB, "error");
                    else maxQustionsError.Clear();
                    if (!checkValidateOfTimePerQuestionTB()) timePerQuestionError.SetError(timePerQuestionTB, "error");
                    else timePerQuestionError.Clear();
                }
            }
        }
    }
}

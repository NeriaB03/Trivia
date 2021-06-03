using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft;
using Newtonsoft.Json;

namespace Client
{
    public partial class Signup : Form
    {
        public Signup()
        {
            InitializeComponent();
        }
        private void checkButtonValidate()
        {
            if (String.IsNullOrEmpty(usernameTB.Text) || String.IsNullOrEmpty(passwordTB.Text) || String.IsNullOrEmpty(emailTB.Text))
            {
                signupButton.Enabled = false;
                signupButton.Cursor = Cursors.No;
                signupButton.BackColor = Color.FromArgb(175, 220, 249);
            }
            else
            {
                signupButton.Enabled = true;
                signupButton.Cursor = Cursors.Hand;
                signupButton.BackColor = Color.FromArgb(41, 128, 185);

            }
        }
        private void loginButton_Click(object sender, EventArgs e)
        {
            Client.Program.isUserExistOrIsPasswordMatch = false;
            this.Close();
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            Client.Program.sock.Close();
            Client.Program.isUserExistOrIsPasswordMatch = false;
            Client.Program.isClosing = true;
            this.Close();
        }

        private void signupButton_Click(object sender, EventArgs e)
        {
            //signup
            object signupUser = new SignupUser
            {
                username = usernameTB.Text.ToString(),
                password = passwordTB.Text.ToString(),
                email = emailTB.Text.ToString()
            };
            string json = JsonConvert.SerializeObject(signupUser, Formatting.Indented);
            string loginReq = '3' + json.Length.ToString("D4") + json;
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(loginReq));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            json = Encoding.ASCII.GetString(bytes,0,bytesRec);
            Console.WriteLine(json);
            if (JsonConvert.DeserializeObject<Status>(json).status == 1)
            {
                Client.Program.isUserExistOrIsPasswordMatch = true;
                this.Close();
            }
            else
            {
                errorOnUsername.SetError(usernameTB, "error");
                userAlreadyExistsLabel.Visible = true;
            }
        }

        private void usernameTB_TextChanged(object sender, EventArgs e)
        {
            checkButtonValidate();
        }

        private void passwordTB_TextChanged(object sender, EventArgs e)
        {
            checkButtonValidate();
        }

        private void emailTB_TextChanged(object sender, EventArgs e)
        {
            checkButtonValidate();
        }
    }
}

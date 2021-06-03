using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft;
using Newtonsoft.Json;

namespace Client
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }
        private void checkButtonValidate()
        {
            if (String.IsNullOrEmpty(usernameTB.Text) || String.IsNullOrEmpty(passwordTB.Text))
            {
                loginButton.Enabled = false;
                loginButton.Cursor = Cursors.No;
                loginButton.BackColor = Color.FromArgb(175, 220, 249);
            }
            else
            {
                loginButton.Enabled = true;
                loginButton.Cursor = Cursors.Hand;
                loginButton.BackColor = Color.FromArgb(41, 128, 185);

            }
        }
        private void closeButton_Click(object sender, EventArgs e)
        {
            Client.Program.sock.Close();
            Client.Program.isUserExistOrIsPasswordMatch = false;
            Client.Program.isClosing = true;
            this.Close();
        }

        private void pictureBox3_MouseDown(object sender, MouseEventArgs e)
        {
            passwordTB.UseSystemPasswordChar = false;
        }

        private void pictureBox3_MouseUp(object sender, MouseEventArgs e)
        {
            passwordTB.UseSystemPasswordChar = true;
        }

        private void signupButton_Click(object sender, EventArgs e)
        {
            Client.Program.isUserExistOrIsPasswordMatch = false;
            this.Close();
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            //login
            object user = new User{
                username=usernameTB.Text.ToString(),
                password=passwordTB.Text.ToString()
            };
            string json = JsonConvert.SerializeObject(user,Formatting.Indented);
            string loginReq = '2' + json.Length.ToString("D4") + json;
            Client.Program.sock.Send(System.Text.Encoding.ASCII.GetBytes(loginReq));
            byte[] bytes = new byte[1024];
            int bytesRec = Client.Program.sock.Receive(bytes);
            json = Encoding.ASCII.GetString(bytes, 0, bytesRec);
            Console.WriteLine(json);
            if (JsonConvert.DeserializeObject<Status>(json).status == 1)
            {
                Client.Program.isUserExistOrIsPasswordMatch = true;
                this.Close();
            }
            else if(JsonConvert.DeserializeObject<Error>(json).Message.Equals("User does not exists..."))
            {
                errorUserDoesNotExists.SetError(usernameTB, "error");
                errorLabel.Visible = true;
                errorLabel.Text = "User does not exists...";
                errorPasswordDoesNotMatch.Clear();
            }
            else if (JsonConvert.DeserializeObject<Error>(json).Message.Equals("Password does not match..."))
            {
                errorPasswordDoesNotMatch.SetError(passwordTB, "error");
                errorLabel.Visible = true;
                errorLabel.Text = "Password does not match...";
                errorUserDoesNotExists.Clear();
            }
            else
            {
                errorUserDoesNotExists.SetError(usernameTB, "error");
                errorLabel.Visible = true;
                errorLabel.Text = "User already connected...";
                errorPasswordDoesNotMatch.Clear();
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
    }
}

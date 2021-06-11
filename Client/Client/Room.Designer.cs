namespace Client
{
    partial class Room
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.panel1 = new System.Windows.Forms.Panel();
            this.currentNumOfPlayersLabel = new System.Windows.Forms.Label();
            this.timePerQuestionLabel = new System.Windows.Forms.Label();
            this.maxNumOfPlayersLabel = new System.Windows.Forms.Label();
            this.numOfQuestionsLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.roomNameLabel = new System.Windows.Forms.Label();
            this.welcomeLabel = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.closeButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.playersList = new Client.SlidingLabel();
            this.leaveButton = new Client.RoundButton();
            this.startButton = new Client.RoundButton();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.panel1.Controls.Add(this.currentNumOfPlayersLabel);
            this.panel1.Controls.Add(this.timePerQuestionLabel);
            this.panel1.Controls.Add(this.maxNumOfPlayersLabel);
            this.panel1.Controls.Add(this.numOfQuestionsLabel);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.roomNameLabel);
            this.panel1.Controls.Add(this.welcomeLabel);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(300, 530);
            this.panel1.TabIndex = 1;
            // 
            // currentNumOfPlayersLabel
            // 
            this.currentNumOfPlayersLabel.AutoSize = true;
            this.currentNumOfPlayersLabel.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.currentNumOfPlayersLabel.ForeColor = System.Drawing.Color.White;
            this.currentNumOfPlayersLabel.Location = new System.Drawing.Point(210, 281);
            this.currentNumOfPlayersLabel.Name = "currentNumOfPlayersLabel";
            this.currentNumOfPlayersLabel.Size = new System.Drawing.Size(19, 21);
            this.currentNumOfPlayersLabel.TabIndex = 11;
            this.currentNumOfPlayersLabel.Text = "0";
            // 
            // timePerQuestionLabel
            // 
            this.timePerQuestionLabel.AutoSize = true;
            this.timePerQuestionLabel.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.timePerQuestionLabel.ForeColor = System.Drawing.Color.White;
            this.timePerQuestionLabel.Location = new System.Drawing.Point(0, 353);
            this.timePerQuestionLabel.Name = "timePerQuestionLabel";
            this.timePerQuestionLabel.Size = new System.Drawing.Size(155, 21);
            this.timePerQuestionLabel.TabIndex = 10;
            this.timePerQuestionLabel.Text = "Time per question: ";
            // 
            // maxNumOfPlayersLabel
            // 
            this.maxNumOfPlayersLabel.AutoSize = true;
            this.maxNumOfPlayersLabel.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.maxNumOfPlayersLabel.ForeColor = System.Drawing.Color.White;
            this.maxNumOfPlayersLabel.Location = new System.Drawing.Point(0, 305);
            this.maxNumOfPlayersLabel.Name = "maxNumOfPlayersLabel";
            this.maxNumOfPlayersLabel.Size = new System.Drawing.Size(237, 21);
            this.maxNumOfPlayersLabel.TabIndex = 9;
            this.maxNumOfPlayersLabel.Text = "Maximum number of players: ";
            // 
            // numOfQuestionsLabel
            // 
            this.numOfQuestionsLabel.AutoSize = true;
            this.numOfQuestionsLabel.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numOfQuestionsLabel.ForeColor = System.Drawing.Color.White;
            this.numOfQuestionsLabel.Location = new System.Drawing.Point(0, 329);
            this.numOfQuestionsLabel.Name = "numOfQuestionsLabel";
            this.numOfQuestionsLabel.Size = new System.Drawing.Size(177, 21);
            this.numOfQuestionsLabel.TabIndex = 8;
            this.numOfQuestionsLabel.Text = "Number of questions: ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(0, 281);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(220, 21);
            this.label1.TabIndex = 7;
            this.label1.Text = "Current number of players: ";
            // 
            // roomNameLabel
            // 
            this.roomNameLabel.AutoSize = true;
            this.roomNameLabel.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.roomNameLabel.ForeColor = System.Drawing.Color.White;
            this.roomNameLabel.Location = new System.Drawing.Point(0, 257);
            this.roomNameLabel.Name = "roomNameLabel";
            this.roomNameLabel.Size = new System.Drawing.Size(113, 21);
            this.roomNameLabel.TabIndex = 6;
            this.roomNameLabel.Text = "Room name: ";
            // 
            // welcomeLabel
            // 
            this.welcomeLabel.AutoSize = true;
            this.welcomeLabel.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.welcomeLabel.ForeColor = System.Drawing.Color.White;
            this.welcomeLabel.Location = new System.Drawing.Point(0, 233);
            this.welcomeLabel.Name = "welcomeLabel";
            this.welcomeLabel.Size = new System.Drawing.Size(108, 21);
            this.welcomeLabel.TabIndex = 1;
            this.welcomeLabel.Text = "Welcome to ";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Client.Properties.Resources.logo;
            this.pictureBox1.Location = new System.Drawing.Point(50, 3);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(200, 200);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // closeButton
            // 
            this.closeButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.closeButton.FlatAppearance.BorderSize = 0;
            this.closeButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.closeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closeButton.Font = new System.Drawing.Font("Verdana", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.closeButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.closeButton.Location = new System.Drawing.Point(720, 0);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(30, 30);
            this.closeButton.TabIndex = 2;
            this.closeButton.Text = "X";
            this.closeButton.UseVisualStyleBackColor = true;
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Century Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(446, 90);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(181, 24);
            this.label2.TabIndex = 6;
            this.label2.Text = "Waiting in room...";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // playersList
            // 
            this.playersList.Font = new System.Drawing.Font("Century Gothic", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.playersList.Location = new System.Drawing.Point(300, 117);
            this.playersList.Name = "playersList";
            this.playersList.Size = new System.Drawing.Size(450, 40);
            this.playersList.Slide = true;
            this.playersList.SlideTime = 25;
            this.playersList.TabIndex = 8;
            // 
            // leaveButton
            // 
            this.leaveButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.leaveButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.leaveButton.Image = global::Client.Properties.Resources.leave;
            this.leaveButton.Location = new System.Drawing.Point(570, 12);
            this.leaveButton.Name = "leaveButton";
            this.leaveButton.Size = new System.Drawing.Size(75, 75);
            this.leaveButton.TabIndex = 5;
            this.leaveButton.UseVisualStyleBackColor = false;
            this.leaveButton.Click += new System.EventHandler(this.leaveButton_Click);
            // 
            // startButton
            // 
            this.startButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.startButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.startButton.Image = global::Client.Properties.Resources.start;
            this.startButton.Location = new System.Drawing.Point(450, 12);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(75, 75);
            this.startButton.TabIndex = 4;
            this.startButton.UseVisualStyleBackColor = false;
            this.startButton.Visible = false;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // Room
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.WhiteSmoke;
            this.ClientSize = new System.Drawing.Size(750, 530);
            this.Controls.Add(this.playersList);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.leaveButton);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.closeButton);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Room";
            this.Text = "Room";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label timePerQuestionLabel;
        private System.Windows.Forms.Label maxNumOfPlayersLabel;
        private System.Windows.Forms.Label numOfQuestionsLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label roomNameLabel;
        private System.Windows.Forms.Label welcomeLabel;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button closeButton;
        private RoundButton startButton;
        private RoundButton leaveButton;
        private System.Windows.Forms.Label currentNumOfPlayersLabel;
        private System.Windows.Forms.Label label2;
        private SlidingLabel playersList;
        private System.Windows.Forms.Timer timer1;
    }
}
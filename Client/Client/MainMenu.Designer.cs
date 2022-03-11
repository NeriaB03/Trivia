namespace Client
{
    partial class MainMenu
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainMenu));
            this.numberOfQuestionsPanel = new System.Windows.Forms.Panel();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.numOfQuestionsTB = new System.Windows.Forms.TextBox();
            this.numberOfPlayersPanel = new System.Windows.Forms.Panel();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.numOfPlayersTB = new System.Windows.Forms.TextBox();
            this.roomNamePanel = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.roomnameTB = new System.Windows.Forms.TextBox();
            this.sendRoomButton = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.timePerQuestionPanel = new System.Windows.Forms.Panel();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.timePerQuestionTB = new System.Windows.Forms.TextBox();
            this.pictureBox6 = new System.Windows.Forms.PictureBox();
            this.errorLabel = new System.Windows.Forms.Label();
            this.maxUsersError = new System.Windows.Forms.ErrorProvider(this.components);
            this.maxQustionsError = new System.Windows.Forms.ErrorProvider(this.components);
            this.timePerQuestionError = new System.Windows.Forms.ErrorProvider(this.components);
            this.correctAnswersPanel = new System.Windows.Forms.Panel();
            this.totalAnswersPanel = new System.Windows.Forms.Panel();
            this.totalAnswersLabel = new System.Windows.Forms.Label();
            this.joinRoomButton = new Client.RoundButton();
            this.createRoomButton = new Client.RoundButton();
            this.statsButton = new Client.RoundButton();
            this.exitButton = new Client.RoundButton();
            this.totalGamesLabel = new System.Windows.Forms.Label();
            this.averageTimeLabel = new System.Windows.Forms.Label();
            this.firstPlaceHighScore = new System.Windows.Forms.Label();
            this.secondPlaceHighScore = new System.Windows.Forms.Label();
            this.thirdPlaceHighScore = new System.Windows.Forms.Label();
            this.numberOfQuestionsPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            this.numberOfPlayersPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            this.roomNamePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.timePerQuestionPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxUsersError)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxQustionsError)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.timePerQuestionError)).BeginInit();
            this.totalAnswersPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // numberOfQuestionsPanel
            // 
            this.numberOfQuestionsPanel.BackColor = System.Drawing.Color.White;
            this.numberOfQuestionsPanel.Controls.Add(this.pictureBox5);
            this.numberOfQuestionsPanel.Controls.Add(this.numOfQuestionsTB);
            this.numberOfQuestionsPanel.Location = new System.Drawing.Point(300, 304);
            this.numberOfQuestionsPanel.Name = "numberOfQuestionsPanel";
            this.numberOfQuestionsPanel.Size = new System.Drawing.Size(450, 60);
            this.numberOfQuestionsPanel.TabIndex = 28;
            this.numberOfQuestionsPanel.Visible = false;
            // 
            // pictureBox5
            // 
            this.pictureBox5.Image = global::Client.Properties.Resources.numberOfQuestions;
            this.pictureBox5.Location = new System.Drawing.Point(0, 0);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(60, 60);
            this.pictureBox5.TabIndex = 10;
            this.pictureBox5.TabStop = false;
            // 
            // numOfQuestionsTB
            // 
            this.numOfQuestionsTB.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numOfQuestionsTB.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.numOfQuestionsTB.Location = new System.Drawing.Point(70, 18);
            this.numOfQuestionsTB.Name = "numOfQuestionsTB";
            this.numOfQuestionsTB.Size = new System.Drawing.Size(370, 27);
            this.numOfQuestionsTB.TabIndex = 9;
            this.numOfQuestionsTB.TextChanged += new System.EventHandler(this.numOfQuestionsTB_TextChanged);
            // 
            // numberOfPlayersPanel
            // 
            this.numberOfPlayersPanel.BackColor = System.Drawing.Color.White;
            this.numberOfPlayersPanel.Controls.Add(this.pictureBox4);
            this.numberOfPlayersPanel.Controls.Add(this.numOfPlayersTB);
            this.numberOfPlayersPanel.Location = new System.Drawing.Point(300, 242);
            this.numberOfPlayersPanel.Name = "numberOfPlayersPanel";
            this.numberOfPlayersPanel.Size = new System.Drawing.Size(450, 60);
            this.numberOfPlayersPanel.TabIndex = 27;
            this.numberOfPlayersPanel.Visible = false;
            // 
            // pictureBox4
            // 
            this.pictureBox4.Image = global::Client.Properties.Resources.numberOfPlayers;
            this.pictureBox4.Location = new System.Drawing.Point(6, 4);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(60, 60);
            this.pictureBox4.TabIndex = 10;
            this.pictureBox4.TabStop = false;
            // 
            // numOfPlayersTB
            // 
            this.numOfPlayersTB.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numOfPlayersTB.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.numOfPlayersTB.Location = new System.Drawing.Point(70, 18);
            this.numOfPlayersTB.Name = "numOfPlayersTB";
            this.numOfPlayersTB.Size = new System.Drawing.Size(370, 27);
            this.numOfPlayersTB.TabIndex = 9;
            this.numOfPlayersTB.TextChanged += new System.EventHandler(this.numOfPlayersTB_TextChanged);
            // 
            // roomNamePanel
            // 
            this.roomNamePanel.BackColor = System.Drawing.Color.White;
            this.roomNamePanel.Controls.Add(this.pictureBox2);
            this.roomNamePanel.Controls.Add(this.roomnameTB);
            this.roomNamePanel.Location = new System.Drawing.Point(300, 180);
            this.roomNamePanel.Name = "roomNamePanel";
            this.roomNamePanel.Size = new System.Drawing.Size(450, 60);
            this.roomNamePanel.TabIndex = 26;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = global::Client.Properties.Resources.roomName;
            this.pictureBox2.Location = new System.Drawing.Point(0, 0);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(60, 60);
            this.pictureBox2.TabIndex = 9;
            this.pictureBox2.TabStop = false;
            // 
            // roomnameTB
            // 
            this.roomnameTB.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.roomnameTB.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.roomnameTB.Location = new System.Drawing.Point(70, 18);
            this.roomnameTB.Name = "roomnameTB";
            this.roomnameTB.Size = new System.Drawing.Size(370, 27);
            this.roomnameTB.TabIndex = 8;
            this.roomnameTB.TextChanged += new System.EventHandler(this.roomnameTB_TextChanged);
            // 
            // sendRoomButton
            // 
            this.sendRoomButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(175)))), ((int)(((byte)(220)))), ((int)(((byte)(249)))));
            this.sendRoomButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.sendRoomButton.Enabled = false;
            this.sendRoomButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.sendRoomButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.sendRoomButton.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sendRoomButton.ForeColor = System.Drawing.Color.White;
            this.sendRoomButton.Location = new System.Drawing.Point(315, 435);
            this.sendRoomButton.Name = "sendRoomButton";
            this.sendRoomButton.Size = new System.Drawing.Size(148, 35);
            this.sendRoomButton.TabIndex = 25;
            this.sendRoomButton.Text = "JOIN";
            this.sendRoomButton.UseVisualStyleBackColor = false;
            this.sendRoomButton.Click += new System.EventHandler(this.sendRoomButton_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label4.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(-1, 225);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(71, 33);
            this.label4.TabIndex = 8;
            this.label4.Text = "JOIN";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label3.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(-1, 307);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(110, 33);
            this.label3.TabIndex = 7;
            this.label3.Text = "CREATE";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label2.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(-1, 389);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(84, 33);
            this.label2.TabIndex = 6;
            this.label2.Text = "STATS";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label1.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(-1, 471);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 33);
            this.label1.TabIndex = 2;
            this.label1.Text = "EXIT";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.joinRoomButton);
            this.panel1.Controls.Add(this.createRoomButton);
            this.panel1.Controls.Add(this.statsButton);
            this.panel1.Controls.Add(this.exitButton);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(300, 530);
            this.panel1.TabIndex = 22;
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
            // timePerQuestionPanel
            // 
            this.timePerQuestionPanel.BackColor = System.Drawing.Color.White;
            this.timePerQuestionPanel.Controls.Add(this.pictureBox3);
            this.timePerQuestionPanel.Controls.Add(this.timePerQuestionTB);
            this.timePerQuestionPanel.Location = new System.Drawing.Point(300, 366);
            this.timePerQuestionPanel.Name = "timePerQuestionPanel";
            this.timePerQuestionPanel.Size = new System.Drawing.Size(450, 60);
            this.timePerQuestionPanel.TabIndex = 29;
            this.timePerQuestionPanel.Visible = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = global::Client.Properties.Resources.time;
            this.pictureBox3.Location = new System.Drawing.Point(0, 0);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(60, 60);
            this.pictureBox3.TabIndex = 10;
            this.pictureBox3.TabStop = false;
            // 
            // timePerQuestionTB
            // 
            this.timePerQuestionTB.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.timePerQuestionTB.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.timePerQuestionTB.Location = new System.Drawing.Point(70, 18);
            this.timePerQuestionTB.Name = "timePerQuestionTB";
            this.timePerQuestionTB.Size = new System.Drawing.Size(370, 27);
            this.timePerQuestionTB.TabIndex = 9;
            this.timePerQuestionTB.TextChanged += new System.EventHandler(this.timePerQuestionTB_TextChanged);
            // 
            // pictureBox6
            // 
            this.pictureBox6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.pictureBox6.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox6.Image")));
            this.pictureBox6.Location = new System.Drawing.Point(611, 0);
            this.pictureBox6.Name = "pictureBox6";
            this.pictureBox6.Size = new System.Drawing.Size(140, 140);
            this.pictureBox6.TabIndex = 24;
            this.pictureBox6.TabStop = false;
            // 
            // errorLabel
            // 
            this.errorLabel.AutoSize = true;
            this.errorLabel.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.errorLabel.Location = new System.Drawing.Point(469, 444);
            this.errorLabel.Name = "errorLabel";
            this.errorLabel.Size = new System.Drawing.Size(147, 17);
            this.errorLabel.TabIndex = 30;
            this.errorLabel.Text = "Room already exists...";
            this.errorLabel.Visible = false;
            // 
            // maxUsersError
            // 
            this.maxUsersError.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.NeverBlink;
            this.maxUsersError.ContainerControl = this;
            // 
            // maxQustionsError
            // 
            this.maxQustionsError.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.NeverBlink;
            this.maxQustionsError.ContainerControl = this;
            // 
            // timePerQuestionError
            // 
            this.timePerQuestionError.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.NeverBlink;
            this.timePerQuestionError.ContainerControl = this;
            // 
            // correctAnswersPanel
            // 
            this.correctAnswersPanel.BackColor = System.Drawing.Color.Orange;
            this.correctAnswersPanel.Location = new System.Drawing.Point(0, 0);
            this.correctAnswersPanel.Name = "correctAnswersPanel";
            this.correctAnswersPanel.Size = new System.Drawing.Size(40, 20);
            this.correctAnswersPanel.TabIndex = 9;
            this.correctAnswersPanel.Visible = false;
            // 
            // totalAnswersPanel
            // 
            this.totalAnswersPanel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(200)))), ((int)(((byte)(200)))), ((int)(((byte)(200)))));
            this.totalAnswersPanel.Controls.Add(this.correctAnswersPanel);
            this.totalAnswersPanel.Location = new System.Drawing.Point(329, 139);
            this.totalAnswersPanel.Name = "totalAnswersPanel";
            this.totalAnswersPanel.Size = new System.Drawing.Size(200, 20);
            this.totalAnswersPanel.TabIndex = 31;
            this.totalAnswersPanel.Visible = false;
            // 
            // totalAnswersLabel
            // 
            this.totalAnswersLabel.AutoSize = true;
            this.totalAnswersLabel.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.totalAnswersLabel.Location = new System.Drawing.Point(326, 102);
            this.totalAnswersLabel.Name = "totalAnswersLabel";
            this.totalAnswersLabel.Size = new System.Drawing.Size(208, 17);
            this.totalAnswersLabel.TabIndex = 10;
            this.totalAnswersLabel.Text = "Correct answers/Total answers:";
            this.totalAnswersLabel.Visible = false;
            // 
            // joinRoomButton
            // 
            this.joinRoomButton.BackColor = System.Drawing.Color.WhiteSmoke;
            this.joinRoomButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.joinRoomButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.WhiteSmoke;
            this.joinRoomButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.WhiteSmoke;
            this.joinRoomButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.joinRoomButton.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.joinRoomButton.Image = global::Client.Properties.Resources.enter;
            this.joinRoomButton.Location = new System.Drawing.Point(105, 202);
            this.joinRoomButton.Name = "joinRoomButton";
            this.joinRoomButton.Size = new System.Drawing.Size(82, 82);
            this.joinRoomButton.TabIndex = 5;
            this.joinRoomButton.UseVisualStyleBackColor = false;
            this.joinRoomButton.Click += new System.EventHandler(this.joinRoomButton_Click);
            // 
            // createRoomButton
            // 
            this.createRoomButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.createRoomButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.createRoomButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.createRoomButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.createRoomButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.createRoomButton.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.createRoomButton.Image = global::Client.Properties.Resources.add;
            this.createRoomButton.Location = new System.Drawing.Point(109, 284);
            this.createRoomButton.Name = "createRoomButton";
            this.createRoomButton.Size = new System.Drawing.Size(82, 82);
            this.createRoomButton.TabIndex = 4;
            this.createRoomButton.UseVisualStyleBackColor = false;
            this.createRoomButton.Click += new System.EventHandler(this.createRoomButton_Click);
            // 
            // statsButton
            // 
            this.statsButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.statsButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.statsButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.statsButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.statsButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.statsButton.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.statsButton.Image = global::Client.Properties.Resources.stats;
            this.statsButton.Location = new System.Drawing.Point(110, 366);
            this.statsButton.Name = "statsButton";
            this.statsButton.Size = new System.Drawing.Size(82, 82);
            this.statsButton.TabIndex = 3;
            this.statsButton.UseVisualStyleBackColor = false;
            this.statsButton.Click += new System.EventHandler(this.statsButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.exitButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.exitButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.exitButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(41)))), ((int)(((byte)(128)))), ((int)(((byte)(185)))));
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.exitButton.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.exitButton.Image = global::Client.Properties.Resources.exit;
            this.exitButton.Location = new System.Drawing.Point(110, 448);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(82, 82);
            this.exitButton.TabIndex = 2;
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // totalGamesLabel
            // 
            this.totalGamesLabel.AutoSize = true;
            this.totalGamesLabel.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.totalGamesLabel.Location = new System.Drawing.Point(329, 176);
            this.totalGamesLabel.Name = "totalGamesLabel";
            this.totalGamesLabel.Size = new System.Drawing.Size(95, 17);
            this.totalGamesLabel.TabIndex = 33;
            this.totalGamesLabel.Text = "Total games: ";
            this.totalGamesLabel.Visible = false;
            // 
            // averageTimeLabel
            // 
            this.averageTimeLabel.AutoSize = true;
            this.averageTimeLabel.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.averageTimeLabel.Location = new System.Drawing.Point(329, 250);
            this.averageTimeLabel.Name = "averageTimeLabel";
            this.averageTimeLabel.Size = new System.Drawing.Size(104, 17);
            this.averageTimeLabel.TabIndex = 34;
            this.averageTimeLabel.Text = "Average Time: ";
            this.averageTimeLabel.Visible = false;
            // 
            // firstPlaceHighScore
            // 
            this.firstPlaceHighScore.AutoSize = true;
            this.firstPlaceHighScore.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.firstPlaceHighScore.Location = new System.Drawing.Point(329, 340);
            this.firstPlaceHighScore.Name = "firstPlaceHighScore";
            this.firstPlaceHighScore.Size = new System.Drawing.Size(127, 17);
            this.firstPlaceHighScore.TabIndex = 35;
            this.firstPlaceHighScore.Text = "First highest score: ";
            this.firstPlaceHighScore.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.firstPlaceHighScore.Visible = false;
            // 
            // secondPlaceHighScore
            // 
            this.secondPlaceHighScore.AutoSize = true;
            this.secondPlaceHighScore.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.secondPlaceHighScore.Location = new System.Drawing.Point(329, 414);
            this.secondPlaceHighScore.Name = "secondPlaceHighScore";
            this.secondPlaceHighScore.Size = new System.Drawing.Size(152, 17);
            this.secondPlaceHighScore.TabIndex = 36;
            this.secondPlaceHighScore.Text = "Second highest score: ";
            this.secondPlaceHighScore.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.secondPlaceHighScore.Visible = false;
            // 
            // thirdPlaceHighScore
            // 
            this.thirdPlaceHighScore.AutoSize = true;
            this.thirdPlaceHighScore.Font = new System.Drawing.Font("Century Gothic", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.thirdPlaceHighScore.Location = new System.Drawing.Point(329, 488);
            this.thirdPlaceHighScore.Name = "thirdPlaceHighScore";
            this.thirdPlaceHighScore.Size = new System.Drawing.Size(133, 17);
            this.thirdPlaceHighScore.TabIndex = 37;
            this.thirdPlaceHighScore.Text = "Third highest score: ";
            this.thirdPlaceHighScore.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.thirdPlaceHighScore.Visible = false;
            // 
            // MainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.WhiteSmoke;
            this.ClientSize = new System.Drawing.Size(750, 530);
            this.Controls.Add(this.thirdPlaceHighScore);
            this.Controls.Add(this.secondPlaceHighScore);
            this.Controls.Add(this.firstPlaceHighScore);
            this.Controls.Add(this.averageTimeLabel);
            this.Controls.Add(this.totalGamesLabel);
            this.Controls.Add(this.totalAnswersLabel);
            this.Controls.Add(this.totalAnswersPanel);
            this.Controls.Add(this.errorLabel);
            this.Controls.Add(this.timePerQuestionPanel);
            this.Controls.Add(this.numberOfQuestionsPanel);
            this.Controls.Add(this.numberOfPlayersPanel);
            this.Controls.Add(this.roomNamePanel);
            this.Controls.Add(this.pictureBox6);
            this.Controls.Add(this.sendRoomButton);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MainMenu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MainMenu";
            this.numberOfQuestionsPanel.ResumeLayout(false);
            this.numberOfQuestionsPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            this.numberOfPlayersPanel.ResumeLayout(false);
            this.numberOfPlayersPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            this.roomNamePanel.ResumeLayout(false);
            this.roomNamePanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.timePerQuestionPanel.ResumeLayout(false);
            this.timePerQuestionPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxUsersError)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxQustionsError)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.timePerQuestionError)).EndInit();
            this.totalAnswersPanel.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel numberOfQuestionsPanel;
        private System.Windows.Forms.TextBox numOfQuestionsTB;
        private System.Windows.Forms.Panel numberOfPlayersPanel;
        private System.Windows.Forms.TextBox numOfPlayersTB;
        private System.Windows.Forms.Panel roomNamePanel;
        private System.Windows.Forms.TextBox roomnameTB;
        private System.Windows.Forms.PictureBox pictureBox6;
        private System.Windows.Forms.Button sendRoomButton;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private RoundButton joinRoomButton;
        private RoundButton createRoomButton;
        private RoundButton statsButton;
        private RoundButton exitButton;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Panel timePerQuestionPanel;
        private System.Windows.Forms.TextBox timePerQuestionTB;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.PictureBox pictureBox4;
        private System.Windows.Forms.PictureBox pictureBox5;
        private System.Windows.Forms.Label errorLabel;
        private System.Windows.Forms.ErrorProvider maxUsersError;
        private System.Windows.Forms.ErrorProvider maxQustionsError;
        private System.Windows.Forms.ErrorProvider timePerQuestionError;
        private System.Windows.Forms.Panel totalAnswersPanel;
        private System.Windows.Forms.Panel correctAnswersPanel;
        private System.Windows.Forms.Label totalAnswersLabel;
        private System.Windows.Forms.Label totalGamesLabel;
        private System.Windows.Forms.Label averageTimeLabel;
        private System.Windows.Forms.Label thirdPlaceHighScore;
        private System.Windows.Forms.Label secondPlaceHighScore;
        private System.Windows.Forms.Label firstPlaceHighScore;
    }
}
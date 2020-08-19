using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace dummyTransferData
{
    public partial class Form1 : Form
    {
        public Form1(){
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e){
            if (File.Exists(@"C:\Users\Paul\Documents\Senior Design Project\coordinate.txt") ){
              File.Delete(@"C:\Users\Paul\Documents\Senior Design Project\coordinate.txt");
            }

            string path = @"C:\Users\Paul\Documents\Senior Design Project\coordinate.txt";
            Random rnd = new Random();
            int angle = rnd.Next(150, 250);
            int distance = rnd.Next(150, 250);
            TextWriter tw = new StreamWriter(path, true);
            tw.Write(angle.ToString());
            tw.Write("split");
            label1.Text = "Moving by an angle of " + angle.ToString() + " degree and extending by " + distance.ToString() + " mm";
            tw.Write(distance.ToString());
            tw.Close();
        }
    }
}

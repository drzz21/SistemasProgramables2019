using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProyectoArduinoSensores
{
    public partial class Form1 : Form
    {
        string cadena = "";
        double temperaturatermistor;
        int tempint;
        double valorvoltaje = 0;
        int temperaturadht;
        int humedaddht;
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.PortName = "COM4";
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            cadena = serialPort1.ReadLine();
            try
            {

                if (cadena.Substring(0, 2) == "S1")
                {
                    //lblActivo1.Visible = true;
                    textBox1.Text = cadena.Substring(2, cadena.Length - 2) + "";

                }
                else if (cadena.Substring(0, 2) == "S2")
                {
                    textBox2.Text = cadena.Substring(2, cadena.Length - 2) + "";
                }
                else if (cadena.Substring(0, 2) == "S3")
                {
                    txtTerm.Text = cadena.Substring(2, cadena.Length - 2) + "";
                }
                else if (cadena.Substring(0, 2) == "S5")
                {
                    textBox5.Text = cadena.Substring(2, cadena.Length - 2);
                }
                else if (cadena.Substring(0, 3) == "S4A")
                {
                    txtTemperaturaDHT.Text = cadena.Substring(3, cadena.Length - 7);
                }
                else if (cadena.Substring(0, 3) == "S4B")
                {
                    txtHumedadDHT.Text = cadena.Substring(3, cadena.Length - 7);
                }
            }
            catch
            {

            }
        }

        bool activado = true;
        private void button1_Click(object sender, EventArgs e)
        {

            if (!activado) {
                button1.Text = "ACTIVADO";
                this.button1.BackColor = Color.FromArgb(77, 255, 22);
                
                serialPort1.Open();
                activado = true;
            }
            else {
                button1.Text = "DESACTIVADO";
                this.button1.BackColor = Color.FromArgb(255, 27, 22);
                serialPort1.Close();
                activado = false;
                    }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            serialPort1.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            try
            {

                if (Int32.Parse(textBox1.Text) < 300)
                {
                    trackBar1.Value = Int32.Parse(textBox1.Text);
                }

                if (Int32.Parse(textBox1.Text) < 20)
                {
                    label6.Text = "MUY CERCA";
                }

                if (Int32.Parse(textBox1.Text) > 20)
                {
                    label6.Text = "CERCA";
                }

                if (Int32.Parse(textBox1.Text) > 100 && Int32.Parse(textBox1.Text) > 200)
                {
                    label7.Text = "MUY LEJOS";
                }

                if (Int32.Parse(textBox1.Text) > 20 && Int32.Parse(textBox1.Text) < 100)
                {
                    label7.Text = "LEJOS";
                }
            }
            catch
            {

            }

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            try
            {
                valorvoltaje = double.Parse(textBox2.Text);

                if (valorvoltaje >= 0.0 && valorvoltaje < 0.3)
                {
                    lblCuantaLuz.Text = "Poca luz :(";
                    btnCuantaLuz.BackColor = Color.FromArgb(255, 44, 21);
                }else if (valorvoltaje >= 0.3 && valorvoltaje < 0.7)
                {
                    lblCuantaLuz.Text = "Luz regular :|";
                    btnCuantaLuz.BackColor = Color.FromArgb(255, 247, 0);
                }
                else if (valorvoltaje >= 0.7 && valorvoltaje < 1.4)
                {
                    lblCuantaLuz.Text = "Mucha Luz :)";
                    btnCuantaLuz.BackColor = Color.FromArgb(19, 255, 0);
                }

                else if (valorvoltaje >= 1.4)
                {
                    lblCuantaLuz.Text = "EXCESO DE LUZ :O";
                    btnCuantaLuz.BackColor = Color.FromArgb(19, 255, 0);
                }
            }
            catch
            {

            }

            

            

            
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            try {
                temperaturatermistor = double.Parse(txtTerm.Text);
                temperaturatermistor = Math.Round(temperaturatermistor,0);
                tempint = (int)temperaturatermistor;
            trackTerm.Value = tempint;
            }
            catch
            {

            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            if (int.Parse(textBox5.Text)==0)
            {
                this.picTilt.Image = Properties.Resources.michaelderecho;
                lblTilt.Text = "RECTO";
            }
            else
            {
                this.picTilt.Image = Properties.Resources.michaelinclinado;
                lblTilt.Text = "INCLINADO";
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            try {
                temperaturadht = int.Parse(txtTemperaturaDHT.Text);
            progressBar1.Value = (int)temperaturadht;
                lblTemp.Text = temperaturadht + "%";
            }
            catch
            {
            }



        }

        private void txtHumedadDHT_TextChanged(object sender, EventArgs e)
        {
            try
            {
                humedaddht = int.Parse(txtHumedadDHT.Text);
                progressBar2.Value = (int)humedaddht;
                lblHum.Text = humedaddht + "%";
            }
            catch
            {
            }
        }
    }
}

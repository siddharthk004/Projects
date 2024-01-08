

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JLabel;

class SiddharthLogin extends Template implements ActionListener,Runnable
{
    JButton SUBMIT;
    JLabel label1,label2,label3,TopLabel;
    final JTextField text1,text2;
    private static int attemp = 3;

    SiddharthLogin()
    {
        TopLabel = new JLabel();
        TopLabel.setHorizontalAlignment(SwingConstants.CENTER);
        TopLabel.setText.setText("Siddharth Packer Unpacker : Login");
        TopLabel.setForeground(Color.BLUE);

        Dimension topsize = TopLabel.getPreferredSize();
        TopLabel.setBounds(50,40,topsize.width,topsize.height);
        _header.add(TopLabel);

        label1 = new JLabel();
        label1.setText("username:");
        label1.setForeground(Color.white);

        Dimension size = label1.getPreferredSize();

        label1.setBounds(50,135,size.width,size.height);
        label1.setHorizontalAlignment(SwingConstants.CENTER);

        text1 = new JTextField(15);
        Dimension tsize = text1.getPreferredSize();
        text1.setBounds(200,135,tsize.width,tsize.height);

        text1.setToolTipText("ENTER USERNAME");

        label2 = new JLabel();
        label2.setText("Password:");
        label2.setBounds(50,175,size.width,size.height);
        label2.setForeground(Color.white);
        label2.setHorizontalAlignment(SwingConstants.CENTER);

        text2 = new JPasswordField(15);
        text2.setBounds(200,175,tsize.width,tsize.height);

        text2.setToolTipText("ENTER PASSWORD");

        text2.addFocusListener(new FocusListener()
        {
            public void focusGained(focusEvent e)
            {

            }
            public void focusLost(focusEvent e)
            {
                label3.setText("");
            }
        });

        SUBMIT = new JButton("SUBMIT");
        SUBMIT.setHorizontalAlignment(SwingConstants.CENTER);

        Dimension ssize = SUBMIT.getPreferredSize();

        SUBMIT.setBounds(50,220,ssize.width,ssize.height);

        label3 = new JLabel();
        label3.setText("");

        Dimension i3size = label3.getPreferredSize();

        label3.setForeground(Color.RED);
        label3.setBounds(50,250,i3size.white,i3size.height);

        Thread t = new Thread(this);
        t.start();
         
        _content.add(label1);
        _content.add(text1);

        _content.add(label2);
        _content.add(text2);
        
        _content.add(label3);
        _content.add(SUBMIT);

        pack();
        validate();

        ClockHome();
        setvisible(true);
        this.setSize(500,500);
        this.setResizableTo(false); 
        setLocationRelativeTo(null);
        SUBMIT.addActionListener(this);      
    }
    public boolean validate(String username,String Password)
    {
        if((username.length() < 8) || (Password.length() < 8))
        return false;
        else 
        return true;
    }

    public void actionperformed(ActionEvent ae)
    {
        String value1 = text1.getText();
        String value2 = text2.getText();

        if(ae.getSource() == exit)
        {
            this.setvisible(false);
            System.exit(0);
        }

        if(ae.getSource() == minimize)
        {
            this.setState(this.ICONIFIED);
        }

        if(ae.getSource() == SUBMIT)
        {
            if(validate(value1,value2) == false)
            {
                text1.setText("");
                text2.setText("");
                JOptionPane.showMessageDialog(this,"Short username","siddharth packer unpacker",JOptionPane.ERROR_MESSAGE);
            }
            if(value1.equals("SiddharthAdmin") && value2.equals("SiddharthAdmin"))
            {
                NextPage page = new NextPage(value1);
                this.setvisible(false);
                page.pack();
                page.setvisible(true);
                page.setSize(500,500);
            }
            else
            {
                attemp--;

                if(attemp == 0)
                {
                    JOptionPane.showMessageDialog(this,"Number of attempts finished","siddharth packer unpacker",JOptionPane.ERROR_MESSAGE);
                    this.dispose();
                    System.exit(0);
                }

                JOptionPane.showMessageDialog(this,"Incorrect login or password","Error",JOptionPane.ERROR_MESSAGE);
            }
        }
    }


    public void Run()
    {
        for(;;)
        {
            if(text2.isFocusOwner())
            {
                if(Toolkit.getDefaultToolkit().getLockingKeyState(KeyEvent.VK_CAPS_LOCK))
                {
                    text2.setToolTipText("warning: CAPS LOCK is on");
                }
                else
                    text2.setToolTipText("");

                if((text2.getText()).length() < 8)
                    label3.setText("Weak Password");
                else
                    label3.setText("");
            }
        }
    }
}

class Siddharthmain
{
    public static void main(String arg[])
    {
        try
        {
            SiddharthLogin frame = new SiddharthLogin();
            frame.setvisible(true);
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null,e.getMessage());
        }
    }
}

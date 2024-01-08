import java.awt.*;
import java.awt.event.*;

class calculator1
{
    public static void main(String Arg[])
    {
        Marvellouscalculator mobj=new Marvellouscalculator(400,400,"Marvellous");
    }
}

class Marvellouscalculator extends WindowAdapter implements ActionListener
{
    public Frame fobj;
    public Button b1,b2,b3,b4;
    public TextField t1,t2;
    public Label lobj;
    public Integer no1,no2;

    public Marvellouscalculator(int width,int height,String title)
    {
        fobj=new Frame(title);
        fobj.setSize(width,height);

        fobj.addWindowListener(this);

        b1=new Button("add");
        b2=new Button("sub");
        b3=new Button("mult");
        b4=new Button("div");

        t1=new TextField();
        t2=new TextField();
        
        b1.setBounds(10,280,80,40);
        b2.setBounds(100,280,80,40);
        b3.setBounds(190,280,80,40);
        b4.setBounds(290,280,80,40);
        
        t1.setBounds(70,100,100,40);
        t2.setBounds(220,100,100,40);

        fobj.add(b1);

        fobj.add(b2);
        fobj.add(b3);
        fobj.add(b4);

        fobj.add(t1);
        fobj.add(t2);

        lobj = new Label();
        lobj.setBounds(150,25,200,100);
        fobj.add(lobj);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);

        //fobj.setlayout(null);
        fobj.setVisible(true); 
    }
    public void windowclosing(WindowEvent obj)
    {
        System.exit(0);
    }
    public void actionPerformed(ActionEvent aobj)
    {
        try
        {
        no1 = Integer.parseInt(t1.getText());
        no2 = Integer.parseInt(t2.getText());

        if(aobj.getSource()==b1)      //add
        {
            lobj.setText("Addition is: "+(no1+no2));
            System.out.println("addition method");
        }
        
        else if(aobj.getSource()==b2)      //add
        {
            lobj.setText("substraction is: "+(no1-no2));
        }
        
        else if(aobj.getSource()==b3)      //add
        {
            lobj.setText("Multiplication is: "+(no1*no2));
        }
        
        else if(aobj.getSource()==b4)      //add
        {
            lobj.setText("division is: "+(no1/no2));
        }

        }
        catch(Exception eobj)
        {
            System.out.println("Exception found");
        }
   }
}
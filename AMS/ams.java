


////////////////////////////////////////////////
//         
//         --- AMS --- 
//    Automated Mail Sender
//         
///////////////////////////////////////////////


////////////////////////////////////////////////
// 
//    name :- Kardile Siddharth Satish
//    name :- Dhonde Dnyaneshwari Badrinath
//    date :- 12-01-2024
// 
///////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Execution CMD Commands
// 
//   for compile
//   javac -cp .;lib/javax.mail.jar;lib/javax.activation.jar;lib/javax.postgresql.jar ams.java
// 
//   for run
//   java -cp .;lib/javax.mail.jar;lib/javax.activation.jar;lib/javax.postgresql.jar ams
// 
//   for run if class not found
//   java -cp .;lib/javax.mail.jar;lib/javax.activation.jar;lib/javax.postgresql.jar ams.java
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////
// 
//     Java Library 
// 
///////////////////////////////////////////////

import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

import javax.mail.*;
import javax.mail.internet.*;

import java.io.*;
import java.util.*;
import java.io.File;
import java.util.List;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Properties;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.Timer;
import javax.swing.JFileChooser;
import javax.activation.DataSource;
import javax.activation.DataHandler;
import javax.activation.FileDataSource;

////////////////////////////////////////////////////////////
//
//     starter of project
//     Login Page
//
////////////////////////////////////////////////////////////

class ams extends JFrame implements ActionListener {
    
    // Buttons and panel Declarations
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JButton clearButton , loginButton;
    private JPanel panel;

    public ams() {
        setTitle("Login Page");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);
        setLocationRelativeTo(null);
        panel = new JPanel() {
            // Apply inline CSS for panel
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Color customColor = new Color(215, 248, 250); 
                setBackground(customColor);
                setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
                setLayout(new GridLayout(3, 2, 10, 10));
            }
        };

        JLabel usernameLabel = new JLabel("Username");
        usernameField = new JTextField();

        JLabel passwordLabel = new JLabel("Password");
        passwordField = new JPasswordField();

        clearButton = new JButton("Clear");
        clearButton.setBackground(new Color(255, 150, 150)); // Light red color
        clearButton.addActionListener(this);

        loginButton = new JButton("Login");
        loginButton.setBackground(new Color(150, 255, 150)); // Light green color
        loginButton.addActionListener(this);

        // add all button and field to the pannel
        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(clearButton);

        // panel.add(new JLabel());          // Placeholder for spacing
        panel.add(loginButton);

        add(panel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        // Handling login button action
        if (e.getSource() == loginButton) {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());

            // Perform login validation here (dummy check for demonstration)
            if (username.equals("admin") && password.equals("root")) {   ///////////////////
                JOptionPane.showMessageDialog(this, "Login Successful!");
                dispose();  // close
                SwingUtilities.invokeLater(firstmail::new);           // calling next page

            } 
            else {
                JOptionPane.showMessageDialog(this, "Invalid Username or Password");  // pop up
            }
        }

        // clear screen for another credential
        else if(e.getSource() == clearButton) 
        {
            usernameField.setText("");
            passwordField.setText("");
        }
    }

    // login page main method
    public static void main(String[] args) {
        SwingUtilities.invokeLater(ams::new);
    }
}


////////////////////////////////////////////////////////////
//
//     2 Option for Page Operate
//     1 - Send Mail
//     2 - Add New Mail
//     3 - Admin Only
//     Second Page
//
////////////////////////////////////////////////////////////

class firstmail extends JFrame implements ActionListener {
    
    public firstmail() {

        setTitle("Mail Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel() {

            // Apply inline CSS for panel
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Color customColor = new Color(215, 248, 250); 
                setBackground(customColor);
                setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
                setLayout(new GridLayout(2, 1, 10, 10));
            }
        };

        // this button will open mail sender page for sending mails
        JButton sendMailButton = new JButton("Send Mail");
        sendMailButton.setBackground(new Color(150, 255, 150)); // Light blue color
        sendMailButton.addActionListener(this);
        
        // this button will open next page that will add new mail to database
        JButton addNewMailButton = new JButton("Add New Mail");
        addNewMailButton.setBackground(new Color(150, 255, 150)); // Light pink color
        addNewMailButton.addActionListener(this);

        // this button will open next page that will Delete mail From the database
        JButton deleteMailButton = new JButton("Delete Mail");
        deleteMailButton.setBackground(new Color(255, 150, 150)); // Light pink color
        deleteMailButton.addActionListener(this);
        
        // this button will open next page that will Delete mail From the database
        JButton ExitButton = new JButton(" Exit ");
        ExitButton.setBackground(new Color(255, 150, 150)); // Light pink color
        ExitButton.addActionListener(this);

        panel.add(sendMailButton);
        panel.add(addNewMailButton);
        panel.add(deleteMailButton);
        panel.add(ExitButton);

        add(panel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) 
    {
        if (e.getActionCommand().equals("Send Mail")) // send mail action
        {
            dispose();  // close
            SwingUtilities.invokeLater(sendmail::new);
        } 

        else if (e.getActionCommand().equals("Add New Mail"))  // add mail page
        {
            dispose();  // close
            SwingUtilities.invokeLater(addnewmailid::new);
        } 

        else if (e.getActionCommand().equals("Delete Mail"))  // admin page
        {
            dispose();  // close
            SwingUtilities.invokeLater(adminlogin::new);
        }

        else if (e.getActionCommand().equals(" Exit "))  // Exit
        {
            System.exit(0);
        }
    }
}


////////////////////////////////////////////////////////////
//
//     Admin Page
//
////////////////////////////////////////////////////////////

class adminlogin extends JFrame implements ActionListener {
    
    // Buttons and panel Declarations
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JButton clearButton , loginButton , backButton;
    private JPanel panel;

    public adminlogin() {

        setTitle("Admin Login Page");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 250);
        setLocationRelativeTo(null);

        panel = new JPanel() {

            // Apply inline CSS for panel
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Color customColor = new Color(215, 248, 250); 
                setBackground(customColor);
                setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
                setLayout(new GridLayout(4, 2, 10, 10));
            }
        };

        JLabel usernameLabel = new JLabel("Username");
        usernameField = new JTextField();
        usernameField.setColumns(20);

        JLabel passwordLabel = new JLabel("Password");
        passwordField = new JPasswordField();
        passwordField.setColumns(20);

        backButton = new JButton("Back");
        backButton.setBackground(new Color(255, 150, 150)); // Light red color
        backButton.addActionListener(this);

        clearButton = new JButton("Clear");
        clearButton.setBackground(new Color(255, 150, 150)); // Light red color
        clearButton.addActionListener(this);

        loginButton = new JButton("Login");
        loginButton.setBackground(new Color(150, 255, 150)); // Light green color
        loginButton.addActionListener(this);

        
        // Increased button sizes
        backButton.setPreferredSize(new Dimension(100, 40));
        // Increased button sizes
        clearButton.setPreferredSize(new Dimension(100, 40));
        // Increased button sizes
        loginButton.setPreferredSize(new Dimension(100, 40));

        // add all button and field to the pannel
        panel.add(usernameLabel);
        panel.add(usernameField);

        panel.add(new JLabel());          // Placeholder for spacing

        panel.add(passwordLabel);
        panel.add(passwordField);

        panel.add(new JLabel());          // Placeholder for spacing

        panel.add(backButton);
        panel.add(clearButton);
        panel.add(loginButton);

        add(panel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {

        // Handling login button action
        if (e.getSource() == loginButton) {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());

            // Perform login validation here (dummy check for demonstration)
            if (username.equals("admin") && password.equals("ams")) {

                JOptionPane.showMessageDialog(this, "Login Successful!");
                dispose();  // close

                SwingUtilities.invokeLater(() -> new DeleteEmailApp().createAndShowGUI());
            } 
            else {
                JOptionPane.showMessageDialog(this, "Invalid Username or Password");  // pop up
            }
        }

        // clear screen for another credential
        else if(e.getSource() == clearButton) 
        {
            usernameField.setText("");
            passwordField.setText("");
        }

        // Back button
        else if(e.getSource() == backButton) 
        {
            dispose();
            SwingUtilities.invokeLater(firstmail::new); // Call previous page
        }
    }
}

////////////////////////////////////////////////
// 
//    delete mail from database
// 
///////////////////////////////////////////////


class DeleteEmailApp extends JFrame {

    private JTextField emailTextField;
    private JComboBox<String> mailComboBox;
    private List<String> mailx;
    private String FilePath = "email.txt";

    public void createAndShowGUI() {

        setTitle("Mail Delete Page");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(850, 300);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel() {
            
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Color customColor = new Color(215, 248, 250);
                setBackground(customColor);
                setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
                setLayout(new GridLayout(4, 2, 10, 10));
            }
        };

        JLabel firstNameLabel = new JLabel("Mail Id :");

        JLabel mailIdLabel = new JLabel("Mail View :");

        // JComboBox<String> firstNameComboBox = new JComboBox<>(getFirstNamesFromDatabase());
        try
        {
            // this line will fetch mail in the form of array and save into the mailx
            mailx = CreateTable.displayTableData();
            String[] mailarr = mailx.toArray(new String[0]);
            
            DefaultComboBoxModel<String> comboBoxModel = new DefaultComboBoxModel<>(mailarr);
            
            // Create and configure the JComboBox
            mailComboBox = new JComboBox<String>(mailarr);

        }
        catch (SQLException e) 
        {
            e.printStackTrace();
        }

        firstNameLabel.setFont(new Font("Arial", Font.BOLD, 15));
        mailIdLabel.setFont(new Font("Arial", Font.BOLD, 15));        
        mailComboBox.setFont(new Font("Arial", Font.BOLD, 13));

        mailComboBox.setEditable(true);        
        mailComboBox.setPreferredSize(new Dimension(600, 35));

        // mailComboBox = new JComboBox<>(getMailIdsFromDatabase());

        emailTextField = new JTextField(50);
        emailTextField.setFont(new Font("Arial", Font.BOLD, 13));

        JButton deleteButton = new JButton("Delete");
        JButton LoadButton = new JButton("Load");
        JButton clearButton = new JButton("Clear");
        JButton backButton = new JButton("Back");
        
        // Increased button sizes
        deleteButton.setPreferredSize(new Dimension(100, 40));
        LoadButton.setPreferredSize(new Dimension(100, 40));
        clearButton.setPreferredSize(new Dimension(100, 40));
        backButton.setPreferredSize(new Dimension(100, 40));

        deleteButton.setBackground(new Color(150, 255, 150));
        LoadButton.setBackground(new Color(255, 255, 150)); // Light yellow color
        clearButton.setBackground(new Color(255, 255, 150)); // Light yellow color
        backButton.setBackground(new Color(255, 150, 150));

        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                deleteEmail();
            }
        });

        
        LoadButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                SwingUtilities.invokeLater(() -> new DeleteEmailApp().createAndShowGUI());
            }
        });

        clearButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                clearFields();
            }
        });

        backButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose(); // Close the current frame
                SwingUtilities.invokeLater(firstmail::new); // Call previous page
            }
        });

        panel.add(firstNameLabel);
        panel.add(emailTextField);
        panel.add(new JLabel()); // Empty label for spacing

        panel.add(mailIdLabel);
        panel.add(mailComboBox);
        panel.add(new JLabel()); // Empty label for spacing

        panel.add(backButton);
        panel.add(LoadButton);
        panel.add(new JLabel()); // Empty label for spacing

        panel.add(clearButton);
        panel.add(deleteButton);

        add(panel);
        setVisible(true);
    }

    // private String[] getFirstNamesFromDatabase() {
    //     // Fetch and return first names from the database (replace with your actual logic)
    //     return new String[]{"John", "Jane", "Alice", "Bob"};
    // }

    // private String[] getMailIdsFromDatabase() {
    //     // Fetch and return mail IDs from the database (replace with your actual logic)
    //     return new String[]{"john@example.com", "jane@example.com", "alice@example.com", "bob@example.com"};
    // }

    
    private void deleteEmail() {
        String emailToDelete = emailTextField.getText();
        
        if (emailToDelete.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter an email to delete.");
            return;
        }

        String url = "jdbc:postgresql://localhost:5433/postgres";
        String user = "postgres";
        String password = "9850";
        String deleteQuery = "DELETE FROM amsdemo2 WHERE email = ?";

        try (Connection connection = DriverManager.getConnection(url, user, password);
            PreparedStatement preparedStatement = connection.prepareStatement(deleteQuery);
            FileWriter writer = new FileWriter(new File(FilePath), true)) {

            preparedStatement.setString(1, emailToDelete);
            int rowsAffected = preparedStatement.executeUpdate();

            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(null, "Email deleted successfully.");
                
                writer.write("\n\n ------------ Mail Delete ------------\n");
                writer.write("Deleted Mail: " + emailToDelete);

                // Refresh the mailComboBox after deletion
                // mailComboBox.setModel(new DefaultComboBoxModel<>(getMailIdsFromDatabase()));
            } else {
                JOptionPane.showMessageDialog(null, "Email not found or deletion failed.");
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(null, "Error executing SQL query.");
        } catch (IOException ioException) {
            ioException.printStackTrace();
            JOptionPane.showMessageDialog(null, "Error writing to log file.");
        }
    }

    public void clearFields() {
        emailTextField.setText("");
    }
}



////////////////////////////////////////////////
// 
//    new mail id add Page
// 
///////////////////////////////////////////////

class addnewmailid extends JFrame implements ActionListener {
    
    // button , field declarations
    private JLabel label1,label2,label3;
    private JTextField text1,text2;
    private JTextArea area1;
    private JComboBox box1;
    private JPanel panel;
    private JButton button1,button2,button3;
    private String FilePath = "email.txt";

    public addnewmailid() {

        setTitle("Add New Mail");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(530, 170);
        setLocationRelativeTo(null);

        panel = new JPanel() {

            // Apply inline CSS for panel
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Color customColor = new Color(215, 248, 250); 
                setBackground(customColor);
            }
        };
        
        // compulsary add your name here
        label1 = new JLabel("Your Name :  ");
        label1.setFont(new Font("Arial", Font.BOLD, 17));
        text1 = new JTextField();
        text1.setPreferredSize(new Dimension(350, 30));

        panel.add(label1);panel.add(text1);
        panel.add(new JLabel());          // Placeholder for spacing

        // Enter Correct mail
        label2 = new JLabel("Mail Id       :  ");
        label2.setFont(new Font("Arial", Font.BOLD, 18));
        text2 = new JTextField();
        text2.setPreferredSize(new Dimension(350, 30)); 

        panel.add(label2);panel.add(text2);

        button1 = new JButton("Submit");
        button1.setBackground(new Color(150, 255, 150)); // Light green color
        button1.setPreferredSize(new Dimension(75, 35));
        button1.addActionListener(this);

        button2 = new JButton("Clear");
        button2.setBackground(new Color(255, 150, 150)); // Light red color
        button2.setPreferredSize(new Dimension(70, 35));
        button2.addActionListener(this);

        button3 = new JButton("Back");
        button3.setBackground(new Color(247, 152, 133)); // Light red color
        button3.setPreferredSize(new Dimension(75, 35));
        button3.addActionListener(this);

        panel.add(button3);panel.add(new JLabel());panel.add(new JLabel());panel.add(button2); panel.add(button1);

        add(panel);
        setVisible(true);

    }
    

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == button1) {
            try {

                // write the sender data into the file
                File file = new File(FilePath);

                if(!file.exists()) {
                    file.createNewFile();
                }
                
                FileWriter writer = new FileWriter(file);

                String name = text1.getText();
                String mail = text2.getText();

                if(name.equals("") || mail.equals("")){
                    JOptionPane.showMessageDialog(this, "Invalid Info!");
                }
                else
                {
                    if(emailvalidation(mail)) 
                    {
                        // Insert data into example_table
                        String[] arr = CreateTable.plpgsql(name, mail,1);

                        writer.write("\n\n ------------ Mail Add ------------\n");
                        writer.write(name+" Added New Mail : "+mail);
                        JOptionPane.showMessageDialog(this, "Mail Added Successful.!");
                        System.out.println("Submit");
                    }
                    else {
                        dispose();  // close
                        JOptionPane.showMessageDialog(this,"Invalid Mail");
                    }
                }
                writer.close();
            }
            catch(IOException k) {
                k.printStackTrace();
            }
        }
        // for clear screen
        else if (e.getSource() == button2) {
            text1.setText("");
            text2.setText("");
        }
        else if(e.getSource() == button3) {
            dispose();  // close
            SwingUtilities.invokeLater(firstmail::new);           // calling next page            
        }
    }
    
    // this function will valid your mail id and then it will add to the database
    public boolean emailvalidation(String email) {
        
        // Regular expression for a simple email validation
        String regex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(email);

        if (matcher.matches()) {
            System.out.println("Valid email address");
            return true;
        } 
        else {
            System.out.println("Invalid email address");
            return false;
        }
    }
}

////////////////////////////////////////////////
// 
//    mail send
// 
///////////////////////////////////////////////

class sendmail extends JFrame implements ActionListener {

    private JLabel label1,label2,label3;
    private JTextField text1;
    private JTextArea area1;
    private JPanel panel;
    private JComboBox<String> box1;
    private JButton fileChooserButton,button1,button2,button3,button4;
    private String name = "",FilePath = "email.txt",img = "",password = "fyrg tlbt epht syzs";
    private List<String> mailx;

    public sendmail() {

        setTitle("Send Mail");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(530, 380);
        setLocationRelativeTo(null);

        panel = new JPanel() {

            // Apply inline CSS for panel
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Color customColor = new Color(215, 248, 250); 
                setBackground(customColor);
            }
        };
        
        label1 = new JLabel("Your Name :  ");
        label1.setFont(new Font("Arial", Font.BOLD, 17));
        text1 = new JTextField();
        text1.setPreferredSize(new Dimension(350, 30));
        panel.add(label1);panel.add(text1);

        label2 = new JLabel("Subject    : ");
        label2.setFont(new Font("Arial", Font.BOLD, 19));
        area1 = new JTextArea(10,35);
        panel.add(label2);panel.add(area1);

        label3 = new JLabel("To        : ");
        // Insert data into example_table
        // String[] mdemo = {"", "siddharthkardile5@gmail.com", "dnyaneshwaridhonde04@gmail.com", "kardilesiddharth55@gmail.com","kardilesiddharth@aca.edu.in"};
        // CreateTable createTableInstance = new CreateTable();
        
        try
        {
            // this line will fetch mail in the form of array and save into the mailx
            mailx = CreateTable.displayTableData();
            String[] mailarr = mailx.toArray(new String[0]);
            
            DefaultComboBoxModel<String> comboBoxModel = new DefaultComboBoxModel<>(mailarr);
            
            // Create and configure the JComboBox
            box1 = new JComboBox<String>(mailarr);

        }
        catch (SQLException e) 
        {
            e.printStackTrace();
        }
        
        label3.setFont(new Font("Arial", Font.BOLD, 20));
        // box1 = new JComboBox();

        // this will choose file from the file manager for the further process
        fileChooserButton = new JButton("Choose File");

        fileChooserButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // get any file from the file manager and define in the img
                img = openFileChooser();
            }
        });


        box1.setFont(new Font("Arial", Font.BOLD, 13));

        box1.setEditable(false);        
        box1.setPreferredSize(new Dimension(400, 30));
        panel.add(label3);panel.add(box1);
        panel.add(fileChooserButton);

        // if user choose any mail or type any mail then the name string will catch that mail
        box1.addItemListener(new ItemListener(){

            public void itemStateChanged(ItemEvent ie){
                name = (String)box1.getSelectedItem();
            }
        });
        
        
        button4 = new JButton("Send All");
        button4.setBackground(new Color(150, 255, 150)); // Light green color
        button4.setPreferredSize(new Dimension(100, 35));
        
        button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                // first valid the mail then further process
                if(emailvalidation(name)) {
                    try {
                        File file = new File(FilePath);

                        if(!file.exists()) {
                            file.createNewFile();
                        }
                        FileWriter writer = new FileWriter(file);
                        for( String mailXa : mailx){

                            String valid = text1.getText();
                            String subject = area1.getText();

                            // if user not enter any user name then this pop up will shown
                            if(valid.equals(""))
                            {
                                JOptionPane.showMessageDialog(sendmail.this,"User Name Is Compulsary");
                            }

                            // if user not enter any mail then this pop up will shown
                            else if(name == ""){
                                JOptionPane.showMessageDialog(sendmail.this,"Mail Id Is Compulsary");
                            }

                            else{
                                // if mail is empty
                                if(mailXa != "")
                                    writer.write("\n\n ------------ Mail Send ------------\n");
                                    
                                    // if file send for the customer
                                    if(img != "") {
                                        sendmailx(subject,mailXa,img); // Add your mail sending logic here
                                        writer.write(valid+" send data to : "+mailXa+" With Some Attachments");
                                    }

                                    // if no file send to the customer  
                                    else{
                                        sendmailx(subject,mailXa); // Add your mail sending logic here
                                        writer.write(valid+" send data to : "+mailXa);
                                    }
                            }
                        }
                        writer.close();
                    }
                    catch(IOException k) {
                        k.printStackTrace();
                    }
                }
                else 
                {
                    // if mail is incorrect
                    JOptionPane.showMessageDialog(sendmail.this,"Invalid Mail");
                }    
            }
        });

        button1 = new JButton("Send");
        button1.setBackground(new Color(150, 255, 150)); // Light green color
        button1.setPreferredSize(new Dimension(70, 35));

        button1.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if(emailvalidation(name)) {

                    try {
                        File file = new File(FilePath);
                        String valid = text1.getText();
                        String subject = area1.getText();
                    
                        if(!file.exists()) {
                            file.createNewFile();
                        }
                        FileWriter writer = new FileWriter(file);

                        if(valid.equals(""))
                        {

                            // user name compulsary type in the first text field
                            JOptionPane.showMessageDialog(sendmail.this,"User name is compulsary");
                        }
                        else{
                            writer.write("\n\n ------------ Mail Send ------------\n");

                            // if file attach
                            if(img != "") {
                                showWaitPopup(2); // Show pop-up with 5 seconds countdown
                                sendmailx(subject,name,img); // Add your mail sending logic here
                                writer.write(valid+" send data to : "+name+" With Some Attachments");
                            }

                            // if no file has attach
                            else{
                                showWaitPopup(2); // Show pop-up with 5 seconds countdown
                                sendmailx(subject,name); // Add your mail sending logic here
                                writer.write(valid+" send data to : "+name);
                            }
                        }
                        writer.close();
                    }
                    catch(IOException k){
                        k.printStackTrace();
                    }
                }
                else { 

                    // if the mail is invalid
                    JOptionPane.showMessageDialog(sendmail.this,"Invalid Mail");
                }
            }
        });

        button2 = new JButton("Clear");
        button2.setBackground(new Color(255, 150, 150)); // Light red color
        button2.setPreferredSize(new Dimension(70, 35));
        button2.addActionListener(this);

        button3 = new JButton("Back");
        button3.setBackground(new Color(247, 152, 133)); // Light red color
        button3.setPreferredSize(new Dimension(75, 35));
        button3.addActionListener(this);

        panel.add(button4);
        panel.add(new JLabel( ));panel.add(new JLabel( ));panel.add(new JLabel( ));
        panel.add(button3);panel.add(new JLabel());panel.add(new JLabel());panel.add(button2); panel.add(button1);

        add(panel);
        setVisible(true);
    }

    public boolean emailvalidation(String email) {
        
        // Regular expression for a simple email validation
        String regex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(email);

        if (matcher.matches()) {
            System.out.println("Valid email address");
            return true;
        } else {
            System.out.println("Invalid email address");
            return false;
        }
    }

    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == button1) {

            // alraedy define that process
            System.out.println("Send");
            
        }

        // for clear screen
        else if (e.getSource() == button2) {
            text1.setText("");
            area1.setText("");
        }

        //  for go back one page
        else if (e.getSource() == button3) {
            dispose();  // close
            SwingUtilities.invokeLater(firstmail::new);           // calling next page               
        }
    }

    // this function will choose the file and return the path of that file to the caller
    private String openFileChooser() {

        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(this);

        if (result == JFileChooser.APPROVE_OPTION) {

            // User selected a file
            String selectedFilePath = fileChooser.getSelectedFile().getAbsolutePath();
            System.out.println("Selected File: " + selectedFilePath);
            return selectedFilePath;
        } 
        else {

            // if file selection is cancelled
            System.out.println("File selection canceled.");
            return "";
        }
    }

    private void showWaitPopup(int seconds) {

        //  this pop is for wait program for 5 second for the avoid the ambiguity of the program for avoid process failure
        JOptionPane optionPane = new JOptionPane("Please wait for 5 seconds.",JOptionPane.INFORMATION_MESSAGE, JOptionPane.DEFAULT_OPTION, null, new Object[]{}, null);

        JDialog dialog = optionPane.createDialog("Sending Mail");

        Timer timer = new Timer(seconds * 1000, new ActionListener() 
        {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.dispose(); // Close the dialog after the specified duration
                
            }
        });

        timer.setRepeats(false); // Do not repeat the timer

        dialog.setDefaultCloseOperation(JDialog.DO_NOTHING_ON_CLOSE);
        timer.start();
        dialog.setVisible(true);
    }

//   for compile
//   javac -cp .;lijava -cp .;lib/javax.mail.jar;lib/javax.activation.jar mailsender.java

//   for run
//   java -cp .;lijava -cp .;lib/javax.mail.jar;lib/javax.activation.jar mailsender

    // this is main program which send mail to customer
    void sendmailx(String Subject,String name) {
    
       // Sender's email credentials
        System.out.println("Hello");
        String fromEmail = "studentdemo9850@gmail.com"; // Replace with your email

        // Receiver's email
        String toEmail = name; // Replace with recipient's email

        // SMTP server configuration
        Properties props = new Properties();
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.host", "smtp.gmail.com"); // Replace with your SMTP server
        props.put("mail.smtp.port", "587"); // Replace with your SMTP port (e.g., 587)

        // Create a session with the SMTP server
        Session session = Session.getInstance(props, new Authenticator() 
        {
            protected PasswordAuthentication getPasswordAuthentication() 
            {
                return new PasswordAuthentication(fromEmail, password);
            }
        });
        try 
        {
            // Create a default MimeMessage object
            MimeMessage message = new MimeMessage(session);

            // Set From: header field of the header
            message.setFrom(new InternetAddress(fromEmail));

            // Set To: header field of the header
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(toEmail));

            // Set Subject: header field
            message.setSubject("Automated Email System ( AES )");

            
            // Create the message body part
            MimeBodyPart messageBodyPart = new MimeBodyPart();
            messageBodyPart.setText(Subject);
                
            // Create a multipart message and add the message body part
            Multipart multipart = new MimeMultipart();
            multipart.addBodyPart(messageBodyPart);
            
            // Set the actual message
            if(Subject == "") {
                message.setText("This email is sent from Automated Mail System.");
            }
            else{
                message.setText(Subject);
            }

            // Send message
            Transport.send(message);
            System.out.println("Email sent successfully!");
            JOptionPane.showMessageDialog(this, "Email Send Successful..!");

        } 
        catch (MessagingException e) 
        {
            // if the mail sending is fail
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Email Send UnSuccessful..!");
        }
    }

    void sendmailx(String Subject,String name,String path) {

       // Sender's email credentials
        System.out.println("Hello");
        String fromEmail = "studentdemo9850@gmail.com"; // Replace with your email

        // Receiver's email
        String toEmail = name; // Replace with recipient's email

        // SMTP server configuration
        Properties props = new Properties();
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.host", "smtp.gmail.com"); // Replace with your SMTP server
        props.put("mail.smtp.port", "587"); // Replace with your SMTP port (e.g., 587)

        // Create a session with the SMTP server
        Session session = Session.getInstance(props, new Authenticator() 
        {
            protected PasswordAuthentication getPasswordAuthentication() 
            {
                return new PasswordAuthentication(fromEmail, password);
            }
        });

        try 
        {
            // Create a default MimeMessage object
            MimeMessage message = new MimeMessage(session);

            // Set From: header field of the header
            message.setFrom(new InternetAddress(fromEmail));

            // Set To: header field of the header
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(toEmail));

            // Set Subject: header field
            message.setSubject("Automated Email System ( AES )");

            
            // Create the message body part
            MimeBodyPart messageBodyPart = new MimeBodyPart();
            messageBodyPart.setText(Subject);
            
            // Create the attachment body part
            MimeBodyPart attachmentBodyPart = new MimeBodyPart();
            FileDataSource source = new FileDataSource(path);
            attachmentBodyPart.setDataHandler(new DataHandler(source));
                        
            // Use the File class to extract the file name
            File file = new File(path);
            String fileName = file.getName();

            attachmentBodyPart.setFileName(fileName); // Set your desired file name
            
            // Create a multipart message
            Multipart multipart = new MimeMultipart();
            multipart.addBodyPart(messageBodyPart);
            multipart.addBodyPart(attachmentBodyPart);

            // Set the content of the message

            // Set the actual message
            if(Subject == "") {
                message.setText("This email is sent from Automated Mail System.");
            }
            else{
                message.setText(Subject);
                message.setContent(multipart);
            }

            // Send message
            Transport.send(message);
            System.out.println("Email sent successfully!");
            JOptionPane.showMessageDialog(this, "Email Send Successful..!");

        } 
        catch (MessagingException e) 
        {
            // if mail send fails
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Email Send UnSuccessful..!");
        }
    }
}

////////////////////////////////////////////////
// 
//    Create Table 
//    Database - postgres 
//    Insert Data
//    Display Data
// 
///////////////////////////////////////////////

////////////////////////////////////////////////
//  
//    Database - plpg sql
// 
//    Server - 127.0.0.1
//    Database - postgres 
//    Port - 5433
//    UserName - postgres
//    PassWord - 9850
// 
///////////////////////////////////////////////

class CreateTable {

        // Declare a static array to store inserted values
        private static String[] array = {};

        static String[] plpgsql(String name,String mail,int id) {
        String url = "jdbc:postgresql://localhost:5433/postgres";
        String user = "postgres";
        String password = "9850";

        try {
            Connection connection = DriverManager.getConnection(url, user, password);
            if(connection != null)
            { 
                System.out.println("Connected to the PostgreSQL server.");

                createTable(connection); // Create the table if not exists

                if(id == 1) {
                    // Insert data into example_table
                    int id1 = insertData(connection,name,mail);

                    System.out.println(name);
                    System.out.println(mail);

                    // Convert the array to an ArrayList
                    // List<String> mailList = new ArrayList<>(List.of(array));
                    // mailList.add(mail);
                    // array = mailList.toArray(new String[0]);
                    return array;
                }
                // else if(id == 2) {
                //     Display the contents of example_table
                //     return (displayTableData());
                //     return Hello; 
                // }
            }
            else {
                System.out.println("Connection Failed");
            }
        }
        catch (SQLException e) 
        {
            e.printStackTrace();
        }
        return array;
    }

    //  create table query of plpg sql
     private static void createTable(Connection connection) throws SQLException {
        Statement statement;

        try {
            String createTableSQL = "CREATE TABLE IF NOT EXISTS amsdemo2 (id SERIAL,name VARCHAR(255) NOT NULL, email VARCHAR(255) NOT NULL, PRIMARY KEY(id));";
            statement = connection.createStatement();

            statement.executeUpdate(createTableSQL);

            System.out.println("Table created successfully.");
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }   

    private static int insertData(Connection connection, String name, String email) throws SQLException {

        String insertQuery = "INSERT INTO amsdemo2 (name, email) VALUES (?, ?) RETURNING id;";

        // String insertQuery = "INSERT INTO amsdemo2 (name, email) VALUES (?, ?);";
        try (PreparedStatement statement = connection.prepareStatement(insertQuery)) {
            statement.setString(1, name);
            statement.setString(2, email);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            int id = resultSet.getInt(1);
            System.out.println("Data inserted successfully. ID: " + id);
            return id;
        }
    }

    public static List<String> displayTableData() throws SQLException {
        String url = "jdbc:postgresql://localhost:5433/postgres";
        String user = "postgres";
        String password = "9850";

        String selectQuery = "SELECT email FROM amsdemo2;";

        // Convert the array to an ArrayList
        List<String> mailList = new ArrayList<>();

        try (Connection connection = DriverManager.getConnection(url, user, password)) 
        {
            System.out.println("Connected to the PostgreSQL server.");

            try (PreparedStatement statement = connection.prepareStatement(selectQuery);
                ResultSet resultSet = statement.executeQuery()) {

                System.out.println("Table Contents:");
                while (resultSet.next()) {
                    //      new element to the ArrayList
                            String newMail = resultSet.getString("email");
                            mailList.add(newMail);
                }
            }
        }
        catch (SQLException e) 
        {
            e.printStackTrace();
        }
            // Convert the ArrayList back to an array
        return mailList;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     -- End -- 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

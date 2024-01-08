import java.net.*;
import java.io.*;

class client
{
    public static void main(String arg[]) throws Exception
    {
        System.out.println("client application is running...");

        System.out.println("client is waiting for connection");
        Socket s = new Socket("localhost",2100);

        PrintStream ps = new PrintStream(s.getOutputStream());

        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
        
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
        String str1,Str2;
        while(!(str1 = br2.readLine()).equals("end"))
        {
            ps.println(str1);
            System.out.println("enter message for server: ");
            Str2 = br1.readLine();
            System.out.println("server says : "+Str2);
        }
        System.out.println("thank you for using chat Messanger...");
    }
}
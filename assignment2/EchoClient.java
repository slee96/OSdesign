import java.net.*;
import java.io.*;

public class EchoClient {

    public static void main(String [] args) {
        String serverName = args[0];
        Socket socket = null;

        BufferedReader serverReader = null;
        BufferedReader stdinReader = null;
        PrintWriter output = null;

        try{
            socket = new Socket(serverName, 8080);
            serverReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            stdinReader = new BufferedReader(new InputStreamReader(System.in));
            output = new PrintWriter(socket.getOutputStream(), true);
            String input;

        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try {
                socket.close();
            } catch (IOException e) {e.printStackTrace();}
        }

    }
}
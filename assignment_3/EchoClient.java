import java.net.*;
import java.io.*;

public class EchoClient {

    public static void main(String [] args) {
        String serverName = null;
        try {
            serverName = args[0];
        }catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Error: No hostname specified in the first argument");
            System.out.println("usage: EchoClient arg1");
            return;
        }catch (Exception e){
            e.printStackTrace();
        }

        Socket socket = null;
        BufferedReader serverReader = null;
        BufferedReader stdinReader = null;
        PrintWriter output = null;

        try {
            socket = new Socket(serverName, 8080);
            serverReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            stdinReader = new BufferedReader(new InputStreamReader(System.in));
            output = new PrintWriter(socket.getOutputStream(), true);
            String input;

            while (true) {
                input = stdinReader.readLine();
                if (input.equals(".")) break;
                output.println(input);
                System.out.print(serverReader.readLine() + "\n");
            }
        }catch (UnknownHostException e) {
            System.out.println("Invalid Host, please specify a valid hostname");
            return;
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try {
                socket.close();
            }catch (NullPointerException e){
                System.out.println("Cannot close connection to 'NULL' host");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
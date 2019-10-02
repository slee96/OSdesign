import java.net.*;
import java.io.*;

public class EchoServer extends Thread {
    private ServerSocket serverSocket;

    public static void main(String[] args) {
        try {
            Thread t = new EchoServer(8080);
            t.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public EchoServer(int port) throws IOException {
        serverSocket = new ServerSocket(port);
    }

    public void run() {
        BufferedReader reader;
        PrintWriter output;
        try {
            // server infinite loop
            while (true) {
                Socket socket = serverSocket.accept();
                reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                output = new PrintWriter(socket.getOutputStream(), true);

                // Response/Echo infinite loop
                while (true) {
                    output.println("Server: " + reader.readLine());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


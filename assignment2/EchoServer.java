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

    }
}


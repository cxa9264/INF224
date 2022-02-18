import UserInterface.PrincipalWindow;

public class Main {

    private static final long serialVersionUID = 1L;

    public static void main(String[] args) {
        System.setProperty("apple.laf.useScreenMenuBar", "true");
        PrincipalWindow principalWindow = new PrincipalWindow();
        principalWindow.createWindow();
    }
}


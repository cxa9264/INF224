package UserInterface;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PrincipalWindow extends JFrame {
    
    private JTextArea mainJTextArea;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;

    public void createWindow() {
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        JPanel southButtonsJPanel = new JPanel();

        JButton addTextJButton1 = new JButton("Ajouter une ligne");
        JButton addTextJButton2 = new JButton("Ajouter une autre ligne");
        JButton quitJButton = new JButton("Terminer");
        
        mainJTextArea = new JTextArea(10, 10);
        // mainJTextArea.setEditable(false);
        mainJTextArea.addKeyListener(new EnterPressedListener());
        JScrollPane textJScrollPane = new JScrollPane(mainJTextArea);

        // create a menu
        JMenuBar jMenuBar = new JMenuBar();
        JMenu jMenu = new JMenu("Menu");
        jMenuBar.add(jMenu);

        // bind listener to menu items
        JMenuItem addText1JMenuItem = new JMenuItem("Ajouter une ligne");
        JMenuItem addText2jMenuItem = new JMenuItem("Ajouter une autre ligne");
        JMenuItem quitJMenuItem = new JMenuItem("Terminer");
        addText1JMenuItem.addActionListener(new AddText1Listener());
        addText2jMenuItem.addActionListener(new AddText2Listener());
        quitJMenuItem.addActionListener(new QuitListener());
        
        // add menu itmes to menu
        jMenu.add(addText1JMenuItem);
        jMenu.add(addText2jMenuItem);
        jMenu.add(quitJMenuItem);

        // create tool bar
        JToolBar jToolBar = new JToolBar();
        JButton addTextToolBarJButton1 = new JButton("Ajouter une ligne");
        JButton addTextToolBarJButton2 = new JButton("Ajouter une ligne");
        JButton quitToolBarJButton = new JButton("Terminer");
        addTextToolBarJButton1.addActionListener(new AddText1Listener());
        addTextToolBarJButton2.addActionListener(new AddText2Listener());
        quitToolBarJButton.addActionListener(new QuitListener());
        
        // add buttons to tool bar
        jToolBar.add(addTextToolBarJButton1);
        jToolBar.add(addTextToolBarJButton2);
        jToolBar.add(quitToolBarJButton);


        // add buttons to jpanel
        southButtonsJPanel.add(addTextJButton1);
        southButtonsJPanel.add(addTextJButton2);
        southButtonsJPanel.add(quitJButton);

        // add listener to quit button
        quitJButton.addActionListener(new QuitListener());
        // add listener to text buttons
        addTextJButton1.addActionListener(new AddText1Listener());
        addTextJButton2.addActionListener(new AddText2Listener());

        // add to jframe
        add(textJScrollPane, BorderLayout.CENTER);
        add(southButtonsJPanel, BorderLayout.SOUTH);
        add(jToolBar, BorderLayout.NORTH);
        setJMenuBar(jMenuBar);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class QuitListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    class AddText1Listener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            mainJTextArea.append("INF224\n");
        }
    }

    class AddText2Listener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            mainJTextArea.append("Travaux Pratiques Java/Swing\n");
        }
    }

    class EnterPressedListener extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                startClient(getLastLine());
            }
        }
    }

    private String getLastLine() {
        String text = mainJTextArea.getText();
        String[] lines = text.split("\n");
        return lines[lines.length-1];
    }

    private void startClient(String request) {
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;

        Client client = null;

        try {
            client = new Client(host, port);
        } catch (Exception e) {
            mainJTextArea.append("\nErr: Client: Couldn't connect to " + host + ": " + port + "\n");
            return;
        }

        mainJTextArea.append("\nClient connected to " + host + ": " + port + "\n");

        String response = client.send(request);
        processResponse(response);

        return;
    }

    private void processResponse(String response) {
        String[] lines = response.split(">");
        for (String line : lines) {
            mainJTextArea.append(line + '\n');
        }
    }
}


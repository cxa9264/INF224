package UserInterface;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PrincipalWindow extends JFrame {
    
    private JTextArea mainJTextArea;

    public void createWindow() {
        JPanel southButtonsJPanel = new JPanel();

        JButton addTextJButton1 = new JButton("Ajouter une ligne");
        JButton addTextJButton2 = new JButton("Ajouter une autre ligne");
        JButton quitJButton = new JButton("Terminer");
        
        mainJTextArea = new JTextArea(10, 10);
        JScrollPane textJScrollPane = new JScrollPane(mainJTextArea);

        JMenu jMenu = new jMenu();
        JMenuBar jMenuBar = new jMenuBar();
        jMenu.add(jMenuBar);

        // add buttons to jpanel
        southButtonsJPanel.add(addTextJButton1);
        southButtonsJPanel.add(addTextJButton2);
        southButtonsJPanel.add(quitJButton);

        // add listener to quit button
        quitJButton.addActionListener(new quitJButtonListener());
        // add listener to text buttons
        addTextJButton1.addActionListener(new addTextJButton1Listener());
        addTextJButton2.addActionListener(new addTextJButton2Listener());

        // add to jframe
        add(textJScrollPane, BorderLayout.CENTER);
        add(southButtonsJPanel, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class quitJButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    class addTextJButton1Listener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            mainJTextArea.append("INF224\n");
        }
    }

    class addTextJButton2Listener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            mainJTextArea.append("Travaux Pratiques Java/Swing\n");
        }
    }
}
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login_page {
    public static void main(String[] args) {
        new Windows();
    }
}

class Windows extends JFrame implements ActionListener {
    JTextField password, id;
    JLabel l, l1, l2;
    JButton login,cancel;

    public Windows() {
        password = new JPasswordField(15);
        id = new JTextField(15);
        login = new JButton("Login");
        cancel = new JButton("Cancel");
        l = new JLabel("Login Page");
        l1 = new JLabel("User Id");
        l2 = new JLabel("Password");
        
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("GUI Form");
        setBounds(200,200,400, 400);
        l.setFont(new Font("Times New Roman", Font.PLAIN, 29));
        l.setBounds(140, 30, 190, 30);

        l1.setFont(new Font("Tahoma", Font.PLAIN, 18));
        l1.setBounds(60, 120, 80, 20);

        l2.setFont(new Font("Tahoma", Font.PLAIN, 18));
        l2.setBounds(60, 170, 80, 20);

        id.setFont(new Font("Tahoma", Font.PLAIN, 17));
        id.setBounds(165, 120, 160, 26);
        
        password.setFont(new Font("Tahoma", Font.PLAIN, 17));
        password.setBounds(165, 170, 160, 26);

        login.setFont(new Font("Tahoma", Font.PLAIN, 20));
        login.setBackground(new Color(150, 255, 225));
        login.setBounds(40, 250, 140, 40);
        login.addActionListener(this);
        
        cancel.setFont(new Font("Tahoma", Font.PLAIN, 20));
        cancel.setBackground(new Color(150, 255, 225));
        cancel.setBounds(210, 250, 140, 40);
        cancel.addActionListener(this);

        add(l);
        add(l1);
        add(id);
        add(l2);
        add(password);
        add(login);
        add(cancel);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==login){
            String pass = password.getText();
            String name = id.getText();
            if (pass.equals("hello")) {
                JOptionPane.showMessageDialog(login, "Welcome "+name);
                dispose();
            } else {
                JOptionPane.showMessageDialog(login, "Incorrect password");
            }
        }
        else if(e.getSource()==cancel){
            JOptionPane.showMessageDialog(cancel, "Are you sure you want to exit ?");
            dispose();
        }
    }
}
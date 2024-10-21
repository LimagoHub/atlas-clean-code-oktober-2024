package de.limago;

import java.awt.*;
import java.awt.event.*;


public class Fenster extends Frame{


    public Fenster()  {

        setSize(300, 300);
        Button button = new Button("Drück mich");
        button.addActionListener(e->ausgabe());
        addWindowListener(new MyWindowListerner());
        add(button);

    }



    public static void main(String[] args) {

        new Fenster().setVisible(true);
    }

    private void ausgabe() {
        System.out.println("Button wurde gedrueckt");
    }

    private void beenden() {
        // Daten speichern
        dispose();
    }

   /*private class ButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            ausgabe();
        }
   }*/

   class MyWindowListerner extends WindowAdapter {
       @Override
       public void windowClosing(final WindowEvent e) {
           beenden();
       }
   }
}

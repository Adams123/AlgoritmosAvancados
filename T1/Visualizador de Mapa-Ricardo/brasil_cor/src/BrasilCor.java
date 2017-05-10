import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.TreeMap;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/**
 * 
 * @author hugo.gualdron
 *
 */
public class BrasilCor {
	public static void main(String args[]){
		try{
			File input;
			File output;
			
			JOptionPane.showMessageDialog(null, "Select Input file");
			JFileChooser chooser = new JFileChooser();
			
			chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
			if(chooser.showOpenDialog(null) != JFileChooser.APPROVE_OPTION){
				JOptionPane.showMessageDialog(null, "yout must selected input file");
				return;
			}
			input = chooser.getSelectedFile();
			
			JOptionPane.showMessageDialog(null, "Select output directory");
			
			chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			if(chooser.showOpenDialog(null) != JFileChooser.APPROVE_OPTION){
				JOptionPane.showMessageDialog(null, "yout must selected output directory");
				return;
			} 
			output = chooser.getSelectedFile();
			
			TreeMap<String, String> map = new TreeMap<String, String>();
			
			BufferedReader reader = new BufferedReader(new FileReader(input));
			String line;
			String [] sections;
			while(reader.ready()){
				line = reader.readLine();
				sections = line.split(":");
				map.put(sections[0], sections[1].substring(1, sections[1].length()-1)); 
			}
			reader.close();
			
			PrintWriter out = new PrintWriter(output.getPath() + File.separator + "brasil.svg");
			String state;
			String color;
			reader = new BufferedReader(new InputStreamReader(BrasilCor.class.getResourceAsStream("brasil.svg")));
			while(reader.ready()){
				line = reader.readLine();
				if(line.contains("id=")){
					state = line.substring(line.indexOf("\"")+1,  line.lastIndexOf("\""));
					//check state
					color = map.get(state);
					if(color != null){
						out.println(line);
						line = reader.readLine();
						line = line.replace("estateColor", color);
					}
				}
				out.println(line);
 
			}
			reader.close();
			out.close();
			
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}

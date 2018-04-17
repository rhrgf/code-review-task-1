import java.util.Scanner;

public class MainApp {
	
	private TextFileWordCount wordCount;
	private FileReaderUtils fileReader;
	private IResultShow resultShower;
	
	public MainApp() {
		wordCount = new TextFileWordCount();
		fileReader = new FileReaderUtils();
		resultShower = new CResultShowInConsole();
		fileReader.setFileHandler(wordCount);
	}
	
	private boolean CountWord(String filePath) {
		boolean res = false;
		fileReader.setFilePath(filePath);
		if (fileReader.handleFile() == true) {
			resultShower.ShowResult(wordCount.getWordFreq());
			res = true;
		}
		return res;
	}
	
	private static void CountWordFromArg(String[] args, MainApp app) {
		if (args.length >= 1) {
			for (String path : args) {
				System.out.println("the word freq in file " + path);
				if (!app.CountWord(path)) {
					System.out.println("error occured during reading file:" + path);
				}
			}
		}
	}
	
	private static void CountWordFromInputPath(MainApp app) {
		System.out.println("Input the file path to count the word num:");
		Scanner sc = new Scanner(System.in);
		String path = sc.nextLine();
		System.out.println("the word freq in file " + path);
		if (!app.CountWord(path)) {
			System.out.println("error occured during reading file:" + path);
		} 
		sc.close();
	}
	
	public static void main(String[] args) {
		MainApp app = new MainApp();
		
		if (!app.CountWord("words.txt")) {
			System.out.println("error while reading words.txt");
		}
		
		return;
	}
	

}

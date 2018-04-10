import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderUtils {
	
	private BufferedReader reader;
	private String filePath;
	private ITextFileHandler fileHandler;
	
	public ITextFileHandler getFileHandler() {
		return fileHandler;
	}

	public void setFileHandler(ITextFileHandler fileHandler) {
		this.fileHandler = fileHandler;
	}

	public String getFilePath() {
		return filePath;
	}

	public void setFilePath(String filePath) {
		this.filePath = filePath;
	}

	public boolean openFile() {
		boolean ret = false;
		closeFile();
		try {
			reader = new BufferedReader(new FileReader(filePath));
			ret = true;
		} catch(FileNotFoundException e) {
			
		}
		return ret;
	}
	
	public void closeFile() {
		if (reader != null) {
			try {
				reader.close();
			} catch (IOException e) {
				
			}
			
		}
	}
	
	public boolean handleFile() {
		boolean ret = false;
		try {
			if (fileHandler != null && openFile() != false)
			{
				ret = fileHandler.handleTextFile(reader);
			}
		} finally {
			closeFile();
		}
		return ret;
	}

	public FileReaderUtils(String filePath, ITextFileHandler fileHandler) {
		super();
		this.filePath = filePath;
		this.fileHandler = fileHandler;
	}

	public FileReaderUtils() {
		super();
		filePath = null;
		fileHandler = null;
	}
	
}

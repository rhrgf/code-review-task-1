package WordsCount;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public abstract class FileHandler {
	private BufferedReader reader;
	private String filePath;
	protected Integer lastError;
	
	public static final int ERR_FILE_NOT_FOUND = 1;
	public static final int ERR_IO_EXCEPTION = 2;
	public static final int ERR_SUCCESS = 0;

	public String GetFilePath() {
		return filePath;
	}

	public void SetFilePath(String filePath) {
		this.filePath = filePath;
	}

	private boolean OpenFile() {
		boolean ret = false;
		CloseFile();
		try {
			reader = new BufferedReader(new FileReader(filePath));
			ret = true;
		} catch(FileNotFoundException e) {
			lastError = ERR_FILE_NOT_FOUND;
		}
		return ret;
	}
	
	private void CloseFile() {
		if (reader != null) {
			try {
				reader.close();
			} catch (IOException e) {
				lastError = ERR_IO_EXCEPTION;
			}
			
		}
	}
	
	public boolean HandleFile() {
		boolean ret = false;
		try {
			if (OpenFile() != false)
			{
				ret = Handle(reader);
			}
		} finally {
			CloseFile();
		}
		return ret;
	}
	
	public abstract boolean Handle(BufferedReader reader);

	public FileHandler(String filePath) {
		super();
		this.filePath = filePath;
		lastError = ERR_SUCCESS;
	}

	public FileHandler() {
		super();
		filePath = null;
		lastError = ERR_SUCCESS;
	}
	
	public int GetLastError() {
		return lastError;
	}
}

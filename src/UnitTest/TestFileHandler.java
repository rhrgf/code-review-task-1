package UnitTest;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import java.io.BufferedReader;
import org.junit.jupiter.api.Test;
import WordsCount.FileHandler;

class MockFileHandler extends FileHandler{
	public String firstLine;
	@Override
	public boolean Handle(BufferedReader reader) {
		try {
			firstLine = reader.readLine();
		}
		catch (Exception e) {
			return false;
		}
		return true;
	}
	
	public MockFileHandler(String path) {
		super(path);
	}
}



public class TestFileHandler {
		
	@Test
	public void TestOpenFileNotFound() {
		MockFileHandler handler = new MockFileHandler("src//UnitTest//FileNotFound.txt");
		assertEquals(handler.HandleFile(), false);
		assertEquals(handler.GetLastError(), MockFileHandler.ERR_FILE_NOT_FOUND);
	}
	
	@Test
	public void TestOpenFileRight() {
		MockFileHandler handler = new MockFileHandler("src//UnitTest//TestText.txt");
		assertEquals(handler.HandleFile(), true);
		assertEquals(handler.GetLastError(), MockFileHandler.ERR_SUCCESS);
		assertEquals(handler.firstLine, "abc def g");
	}
}

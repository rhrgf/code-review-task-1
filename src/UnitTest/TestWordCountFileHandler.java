package UnitTest;

import static org.junit.jupiter.api.Assertions.assertEquals;
import java.io.BufferedReader;
import java.io.StringReader;
import java.util.Map;
import org.junit.jupiter.api.Test;
import WordsCount.LineCountFileHandler;

public class TestWordCountFileHandler {
	
	@Test
	public void TestHandleMethodRight() {
		LineCountFileHandler handler = new LineCountFileHandler(null);
		String test = "This This is a is This";
		StringReader  strReader = new StringReader(test);
		BufferedReader reader = new BufferedReader(strReader);
		boolean bRet = handler.Handle(reader);
		assertEquals(bRet, true);
		Map<String, Integer> maps = handler.GetWordFreqMap();
		assertEquals(maps.get("This"), (Integer)3);
		assertEquals(maps.get("is"), (Integer)2);
		assertEquals(maps.get("a"), (Integer)1);
	}
	
}

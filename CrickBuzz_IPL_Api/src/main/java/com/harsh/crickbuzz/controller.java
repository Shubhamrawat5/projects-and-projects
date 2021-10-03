package com.harsh.crickbuzz;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

import org.json.JSONObject;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/v1")
public class controller {
	@GetMapping("/score")
	public ResponseEntity<Object> getScore() {
		try {
			Date d = new Date(); //current
			 Date d1 = new GregorianCalendar(2021, Calendar.SEPTEMBER, 20).getTime();//32 match

			if(d.after(d1)) {
				long difference_In_Time
                = d.getTime() - d1.getTime();
				 long difference_In_Days
	                = (difference_In_Time
	                   / (1000 * 60 * 60 * 24))
	                  % 365;
				 System.out.println(difference_In_Days);
				 int a = 37557;
				 long diff  = a+(difference_In_Days*5);
				 StringBuffer result = new StringBuffer();
					URL url = new URL("https://cricket-api.vercel.app/cri.php?url=https://www.cricbuzz.com/live-cricket-scores/"+diff);
					HttpURLConnection conn = (HttpURLConnection) url.openConnection();
				    conn.setRequestMethod("GET");
				    BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
				    for (String line; (line = reader.readLine()) != null; ) {
			              result.append(line);
			          }
				    System.out.println(result);
				    JSONObject myResponse = new JSONObject(result.toString());
				    return new ResponseEntity<Object>(myResponse.toMap(),HttpStatus.OK);
			}else {
				return new ResponseEntity<Object>("bad Luck",HttpStatus.OK);
			}
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return  new ResponseEntity<Object>("bad Luck",HttpStatus.OK);
	}
}

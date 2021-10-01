package com.harsh.statistics;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.harsh.statistics.model.Data;
import com.harsh.statistics.model.Stats;
import com.harsh.statistics.service.StatService;

@RestController
@RequestMapping("/calc")
public class controllermain {
	private final StatService statservice;
	@Autowired
	public controllermain(StatService statservice) {
		super();
		this.statservice = statservice;
	}
	@GetMapping("/regression")
	public ResponseEntity<Stats> getStats(@RequestBody Data data){
		if(data.getDx().size()!=data.getDy().size()) {
			return new ResponseEntity<>(null,HttpStatus.BAD_REQUEST);
		}
		Stats s = statservice.getAll(data);
		return new ResponseEntity<>(s,HttpStatus.OK);
	}
}

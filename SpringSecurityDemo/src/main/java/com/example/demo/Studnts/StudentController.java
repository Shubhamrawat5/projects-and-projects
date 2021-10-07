package com.example.demo.Studnts;

import java.util.Arrays;
import java.util.List;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("api/v1/students")
public class StudentController {
	private static final List<Student> STUDENTS =Arrays.asList(new Student (1,"Harsh"),
			new Student(2,"rahul"),
			new Student(3,"Anna"));
	@GetMapping(path="/{studentsId}")
	public Student getStudent(@PathVariable("studentsId")Integer stduentsId) {
		return STUDENTS.stream()
				.filter(student->stduentsId.equals(student.getStudentsId()))
				.findFirst()
				.orElseThrow(()->new IllegalStateException("Student"+ stduentsId + "not exists"));
		
	}
}

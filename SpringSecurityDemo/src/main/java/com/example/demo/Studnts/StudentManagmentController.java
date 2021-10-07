package com.example.demo.Studnts;

import java.util.Arrays;
import java.util.List;

import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("managment/api/v1/students")
public class StudentManagmentController {
	private static final List<Student> STUDENTS =Arrays.asList(new Student (1,"Harsh"),
			new Student(2,"rahul"),
			new Student(3,"Anna"));
	//we can also setup a check on the methods for security instead of giving antmatchers in sec config
	@GetMapping
	@PreAuthorize("hasAnyRole('ROLE_ADMIN','ROLE_ADMINTANEE')")
	public List<Student> getAllStudents(){
		return STUDENTS;
	}
	@PostMapping
	@PreAuthorize("hasAuthority('student:write')")
	public void register(@RequestBody Student student) {
		System.out.println(student);
	}
	@DeleteMapping(path= "{id}")
	@PreAuthorize("hasAuthority('student:write')")
	public void delete(@PathVariable("id") Integer id) {
		System.out.println(id);
	}
	@PutMapping(path= "{id}")
	@PreAuthorize("hasAuthority('student:write')")
	public void update(@PathVariable("id") Integer id,@RequestBody Student student) {
		System.out.println(String.format("%s,%s",student,id));
	}
}

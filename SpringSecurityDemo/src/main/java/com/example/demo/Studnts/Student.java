package com.example.demo.Studnts;

public class Student {
	private final Integer studentsId;
	private final String studentsName;
	public Student(Integer studentsId, String studentsName) {
		super();
		this.studentsId = studentsId;
		this.studentsName = studentsName;
	}
	public Integer getStudentsId() {
		return studentsId;
	}
	public String getStudentsName() {
		return studentsName;
	}
	@Override
	public String toString() {
		return "Student [studentsId=" + studentsId + ", studentsName=" + studentsName + "]";
	}
	
}

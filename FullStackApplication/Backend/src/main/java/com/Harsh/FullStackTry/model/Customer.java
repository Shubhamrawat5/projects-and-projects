package com.Harsh.FullStackTry.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity(name="customer")
@Table
public class Customer{
	@Id
	@Column(nullable=false)
	private long id;
	@Column(name="name")
	private String name;
	@Column(name="username")
	private String username;
	@Column(name="password")
	private String password;
	@Column(name="email")
	private String email;
	@Column(name="imgUrl")
	private String imgUrl;
	public Customer() {};
	public Customer(long id, String name, String username, String password, String email, String imgUrl) {
		this.id = id;
		this.name = name;
		this.username = username;
		this.password = password;
		this.email = email;
		this.imgUrl = imgUrl;
	}
	public long getId() {
		return id;
	}
	public void setId(long id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getImgUrl() {
		return imgUrl;
	}
	public void setImgUrl(String imgUrl) {
		this.imgUrl = imgUrl;
	}
	@Override
	public String toString() {
		return "Customer [id=" + id + ", name=" + name + ", username=" + username + ", password=" + password
				+ ", email=" + email + ", imgUrl=" + imgUrl + "]";
	}
	
	
}

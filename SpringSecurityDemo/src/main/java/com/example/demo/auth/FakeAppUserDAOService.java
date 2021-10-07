package com.example.demo.auth;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Repository;

import com.example.demo.security.ApplicationUserRole;
import com.google.common.collect.Lists;

@Repository("fake")
//this is a databaase and we have given it a name fake
public class FakeAppUserDAOService implements AppUserDAO{
	private final PasswordEncoder passwordencoder;
	@Autowired
	public FakeAppUserDAOService(PasswordEncoder passwordencoder) {
		this.passwordencoder = passwordencoder;
	}
	@Override
	public Optional<AppUser> selectAppuserByusername(String username) {
		// TODO Auto-generated method stub
		return getAppUsers().stream().filter(appusers->username.equals(appusers.getUsername())).findFirst();
	}
	private List<AppUser> getAppUsers(){
		List<AppUser>  au  = Lists.newArrayList(
				new AppUser(
					"Harsh",
					 passwordencoder.encode("toor"),
					 ApplicationUserRole.STUDENT.getGrantedAuthorities(),
					 true,
					 true,
					 true,
					 true
				),
				new AppUser(
						"linda",
						 passwordencoder.encode("toor"),
						 ApplicationUserRole.ADMIN.getGrantedAuthorities(),
						 true,
						 true,
						 true,
						 true
					),
				new AppUser(
						"tom",
						 passwordencoder.encode("toor"),
						 ApplicationUserRole.ADMINTRANEE.getGrantedAuthorities(),
						 true,
						 true,
						 true,
						 true
					)
		);
		return au;
	}
}

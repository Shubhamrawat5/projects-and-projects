package com.example.demo.auth;

import java.util.Optional;
//this is the interface or repo
//this is our interface
public interface AppUserDAO {
	public Optional<AppUser> selectAppuserByusername(String username);
}

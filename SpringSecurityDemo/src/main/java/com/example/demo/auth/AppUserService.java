package com.example.demo.auth;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
//this class is same as business service or it just helps spring to fetch details of user from database
@Service
public class AppUserService  implements UserDetailsService{
	
	private final AppUserDAO appuserdao;
	@Autowired
	//here in quealifier we mention which database we are wanting to use
	public AppUserService(@Qualifier("fake") AppUserDAO appuserdao) {
		super();
		this.appuserdao = appuserdao;
	}

	@Override
	public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
		// TODO Auto-generated method stub
		return appuserdao.selectAppuserByusername(username)
				.orElseThrow(()->new UsernameNotFoundException(String.format("username %s not found", username)));
	}

}

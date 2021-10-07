package com.example.demo.jwt;

import java.io.IOException;
import java.time.LocalDate;
import java.util.Date;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;

import com.fasterxml.jackson.databind.ObjectMapper;

import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.security.Keys;

//job is this class is to verify the jwt token
//spring does verify the tkens but we can overwrite our own verification
//this is a filter which filters the request before it reaches the API
//we can have many requests filter 
public class Jwtusernamepasswordauthenticationfilter extends UsernamePasswordAuthenticationFilter{

	private final AuthenticationManager authenticationManager;
	public Jwtusernamepasswordauthenticationfilter(AuthenticationManager authenticationManager) {
		super();
		this.authenticationManager = authenticationManager;
	}
	//here the client will send the credentials and then credentials will be validated
	//if all is good then we will generate a JWT token for that client
	@Override
	public Authentication attemptAuthentication(HttpServletRequest request, HttpServletResponse response)
			throws AuthenticationException {
		// TODO Auto-generated method stub
		try {
			usernameandpassauthenticationrequest authenticationreq = new ObjectMapper().readValue(request.getInputStream(),usernameandpassauthenticationrequest.class);
			
			//this will fetch username which is the principal and password 
			Authentication authentication=new UsernamePasswordAuthenticationToken(authenticationreq.getUsername(), authenticationreq.getPassword());
			//this will check that the username exists and if exists then the pass is correct or not
			Authentication authenticate = authenticationManager.authenticate(authentication);
			//if above is correct then this request wll b authenticated
			return authenticate;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			throw new RuntimeException(e);
		}
	}
	//this will be invoked after the above method is succesfull
	//iin this method we are going to generate a JWT token and sent it to the client
	@Override
	protected void successfulAuthentication(HttpServletRequest request, HttpServletResponse response, FilterChain chain,
			Authentication authResult) throws IOException, ServletException {
		// TODO Auto-generated method stub
		//this is the JWT token key
		String key = "securesecuresecuresecuresecuresecure";
		//building the token
		String token = Jwts.builder()
			.setSubject(authResult.getName())
			.claim("authorities", authResult.getAuthorities())
			.setIssuedAt(new Date())
			.setExpiration(java.sql.Date.valueOf(LocalDate.now().plusWeeks(2)))
			.signWith(Keys.hmacShaKeyFor(key.getBytes()))
			.compact();		
		//sending the token
		
		response.addHeader("Authorization","Bearer "+token);
		
	}
}

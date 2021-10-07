package com.example.demo.jwt;

import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.filter.OncePerRequestFilter;

import com.google.common.base.Strings;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jws;
import io.jsonwebtoken.JwtException;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.security.Keys;
//it involves the filter for atlest once in any request
public class JwtTokenVerifierFilter extends OncePerRequestFilter{

	@Override
	protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		//getting the token from the header of the request to verify 
		String authorizationHeader = request.getHeader("Authorization");
		if(Strings.isNullOrEmpty(authorizationHeader)|| !authorizationHeader.startsWith("Bearer ")) {
			//request has been rejected as there is no JWT token found in the request
			filterChain.doFilter(request, response);
			return;
		}
		String token = authorizationHeader.replace("Bearer ","");
		try {
			//removing bearer keyword from the token
			String secretkey = "securesecuresecuresecuresecuresecure";
			
			Jws<Claims> parseClaimsJws = Jwts
				.parserBuilder()
				.setSigningKey(Keys.hmacShaKeyFor(secretkey.getBytes()))
				.build()
				.parseClaimsJws(token);
			
			
			
			
			
			
			Claims body = parseClaimsJws.getBody();
			//getting the name from the token
			String username = body.getSubject();
			//here we have got all the authorities of the user 
			List<Map<String,String>> authorities = (List<Map<String,String>>)body.get("authorities");
		
			
			Set<SimpleGrantedAuthority> SimpleGrantedAuth = authorities
				.stream()
				.map(m->new SimpleGrantedAuthority(m.get("authority")))
				.collect(Collectors.toSet());

			Authentication authentication = new UsernamePasswordAuthenticationToken(
					username, 
					null,
					SimpleGrantedAuth
			);
			SecurityContextHolder.getContext().setAuthentication(authentication);
		}catch(JwtException e) {
			throw new IllegalStateException(String.format("token %s cannot be trusted", token));
		}
		//passing on if verified
		filterChain.doFilter(request, response);
	}

}

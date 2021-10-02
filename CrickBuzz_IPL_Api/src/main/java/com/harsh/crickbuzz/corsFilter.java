package com.harsh.crickbuzz;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Component;

@Component
public class corsFilter implements Filter{

	@Override
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
		// TODO Auto-generated method stub
		HttpServletRequest req = (HttpServletRequest) request;
		HttpServletResponse res = (HttpServletResponse) response;
		res.setHeader("Access-Control-Allow-Origin", req.getHeader("Origin"));
		res.setHeader("Access-Control-Allow-Credentials","true");
		res.setHeader("Access-Control-Allow-Methods","POST,PUT,PATCH,GET,DELETE,OPTIONS");
		res.setHeader("Access-Control-Max-Age","3600");
		res.setHeader("Access-Control-Allow-Headers","Content-Type,Content-Length,Accept,X-Requested-With,remember-me,roleType,authToken");
		chain.doFilter(request, response);
	}

}

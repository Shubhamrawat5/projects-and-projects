package com.example.demo.security;

import java.util.concurrent.TimeUnit;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.dao.DaoAuthenticationProvider;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.config.http.SessionCreationPolicy;
import org.springframework.security.crypto.password.PasswordEncoder;

import com.example.demo.auth.AppUserService;
import com.example.demo.jwt.JwtTokenVerifierFilter;
import com.example.demo.jwt.Jwtusernamepasswordauthenticationfilter;

@Configuration
@EnableWebSecurity
//telling sec config that we want to enable preAuth check
@EnableGlobalMethodSecurity(prePostEnabled = true)
//this class defines security config for whole app
public class AppSecurityConfig extends WebSecurityConfigurerAdapter{
	
	private final AppUserService appuserservice;
	private final PasswordEncoder passwordEncoder;
	
	@Autowired
	public AppSecurityConfig(AppUserService appuserservice, PasswordEncoder passwordEncoder) {
		super();
		this.appuserservice = appuserservice;
		this.passwordEncoder = passwordEncoder;
	}
	@Override
	protected void configure(HttpSecurity http)throws Exception{
		//we want to authorize the request any request in app we want client to provide
		//username and pass in httpbasic  mode
		//in basic auth we cant logout 
		//every single request username and passwaord is been sent
		//with antMatchers we permit some endpoints which can be accesed via browser without auth
		
		
		//only disable csrf when you are testing and ur service doesnt include any sensitive parts
		http
		.csrf().disable()//TODO important part
		//this line helps us know and view what the token is during testing time
		//.csrf().csrfTokenRepository(CookieCsrfTokenRepository.withHttpOnlyFalse())
		//.and()
		
		//now here we can replace form auth or basic auth and add filter
		//this is stateless and not be stored in a database
		.sessionManagement().sessionCreationPolicy(SessionCreationPolicy.STATELESS)
		.and()
		.addFilter(new Jwtusernamepasswordauthenticationfilter(authenticationManager()))
		.addFilterAfter(new JwtTokenVerifierFilter(), Jwtusernamepasswordauthenticationfilter.class)
		.authorizeRequests().antMatchers("/","index","/css/*","/js/*").permitAll()
		//giving access based on roles
		.antMatchers("/api/**").hasRole(ApplicationUserRole.STUDENT.name())
		//giving access based on permision 
//		.antMatchers(HttpMethod.DELETE, "/managment/api/**").hasAuthority(AppUserPermision.COURSE_WRITE.getPermission())
//		.antMatchers(HttpMethod.POST,"/managment/api/**").hasAuthority(AppUserPermision.COURSE_WRITE.getPermission())
//		.antMatchers(HttpMethod.PUT,"/managment/api/**").hasAuthority(AppUserPermision.COURSE_WRITE.getPermission())
//		.antMatchers(HttpMethod.GET,"/managment/api/**").hasAnyRole(ApplicationUserRole.ADMIN.name(),ApplicationUserRole.ADMINTRANEE.name())
		.anyRequest()
		.authenticated();
//		.and()
		//here we were using form based and basic auth methods for security
//		.formLogin()
//		//now if we want to use custom login page just provide its url
//		//for sake of now i will be using thymeleaf and make a page in this project itself
//			.loginPage("/login").permitAll()
//			.defaultSuccessUrl("/courses", true)
//			.passwordParameter("password")
//			.usernameParameter("username")
//		.and()
//		//adding this for making our session id last for 2 weeks default
//		.rememberMe()
//			//how to extend session of remember me and give custom key
//			.tokenValiditySeconds((int)TimeUnit.DAYS.toSeconds(21))
//			.key("hashing name")
//			.rememberMeParameter("remember-me")
//		//we should use form based auth instead of basic
//		//.httpBasic();
//		.and()
//		.logout()
//			.logoutUrl("/logout")
//			.clearAuthentication(true)
//			.invalidateHttpSession(true)
//			.deleteCookies("JSESSIONID","remember-me")
//			.logoutSuccessUrl("/login");
	}
//	@Override
//	@Bean
//	//here we are going to define how we willretrieve users from the Database
//	protected UserDetailsService userDetailsService(){
//		//using the defined roles for new users
//		UserDetails user= User.builder() 
//			.username("Harsh")
//			.password(passwordEncoder.encode("toor"))
//			//.roles(ApplicationUserRole.STUDENT.name())
//			//giving authentication based on permissions
//			.authorities(ApplicationUserRole.STUDENT.getGrantedAuthorities())
//			.build();
//		UserDetails lindaUser= User.builder()
//			.username("linda")
//			.password(passwordEncoder.encode("toor"))
//			//.roles(ApplicationUserRole.ADMIN.name())
//			.authorities(ApplicationUserRole.ADMIN.getGrantedAuthorities())
//			.build();
//		
//		UserDetails tom = User.builder()
//				.username("tom")
//				.password(passwordEncoder.encode("toor"))
//				//.roles(ApplicationUserRole.ADMINTRANEE.name())
//				.authorities(ApplicationUserRole.ADMINTRANEE.getGrantedAuthorities())
//				.build();
//		return new InMemoryUserDetailsManager(
//				user,
//				lindaUser,
//				tom
//			);
//		
//	}
	
	//now we will not use inmemory usename and users we would fetch them from AppUserService
	//we need to configure from where the user details will come
	@Override
	protected void configure(AuthenticationManagerBuilder auth) throws Exception {
		auth.authenticationProvider(daoAuthenticationProvider());
	}
	//here we are using service to fetch data and telling provider to use that service
	@Bean
	public DaoAuthenticationProvider daoAuthenticationProvider() {
		DaoAuthenticationProvider provider = new DaoAuthenticationProvider();
		provider.setPasswordEncoder(passwordEncoder);
		provider.setUserDetailsService(appuserservice);
		return provider;
	}
}

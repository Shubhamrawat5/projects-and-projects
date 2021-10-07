package com.example.demo.security;
//defining types of user roles for the app

import java.util.Set;
import java.util.stream.Collector;
import java.util.stream.Collectors;

import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;

import com.google.common.collect.Sets;

public enum ApplicationUserRole {
	STUDENT(Sets.newHashSet()),
	ADMIN(Sets.newHashSet(AppUserPermision.COURSE_READ,
			AppUserPermision.COURSE_WRITE,
			AppUserPermision.STUDENT_READ,
			AppUserPermision.STUDENT_WRITE)),
	ADMINTRANEE(Sets.newHashSet(AppUserPermision.STUDENT_READ,
			AppUserPermision.COURSE_READ
			));
	private final Set<AppUserPermision> permisions;

	private ApplicationUserRole(Set<AppUserPermision> permisions) {
		this.permisions = permisions;
	}

	public Set<AppUserPermision> getPermisions() {
		return permisions;
	}
	public Set<SimpleGrantedAuthority> getGrantedAuthorities(){
		Set<SimpleGrantedAuthority> permissions = getPermisions().stream()
		.map(permisions->new SimpleGrantedAuthority(permisions.getPermission()))
		.collect(Collectors.toSet());
		permissions.add(new SimpleGrantedAuthority("ROLE_"+this.name()));
		return permissions;
	}
	
}

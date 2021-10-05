import { Component, OnInit } from '@angular/core';
import { Customer } from '../customer';
import { CustomerService } from '../customer.service';
import { HttpErrorResponse } from '@angular/common/http';
import { NgForm } from '@angular/forms';
@Component({
  selector: 'app-delete-one',
  templateUrl: './delete-one.component.html',
  styleUrls: ['./delete-one.component.css']
})
export class DeleteOneComponent implements OnInit {
  public viewOnDelete!:string;
  constructor(private customerService:CustomerService) { }

  ngOnInit(): void {
  //  this.onDeleteCustomer(5);
  }
  public onDeleteCustomer(customerId: number): void {
    this.customerService.deleteEmployee(customerId).subscribe(
      (response: void) => {
        console.log(response);
        this.viewOnDelete="yes";
      },
      (error: HttpErrorResponse) => {
        alert(error.message);
      }
    );
  }
}

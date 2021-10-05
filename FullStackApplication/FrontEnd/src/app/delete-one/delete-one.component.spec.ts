import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DeleteOneComponent } from './delete-one.component';

describe('DeleteOneComponent', () => {
  let component: DeleteOneComponent;
  let fixture: ComponentFixture<DeleteOneComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DeleteOneComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DeleteOneComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
